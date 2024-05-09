#include "philo.h"

void    print(t_philo *philo, unsigned long time, char *action)
{
    pthread_mutex_lock(philo->print);
    printf("%lums   %d %s\n", time, philo->id, action);
    pthread_mutex_unlock(philo->print);
}

void    *routine(void *p)
{
    t_philo *philo;

    philo = (t_philo *)p;
    if ((philo->id % 2) == 0)
        usleep(10);
    philo->last_meal = get_time();
    while (1)
    {
        pthread_mutex_lock(&philo->mutex[philo->id - 1]);
        print(philo, real_time(philo), "has taken a fork");
        pthread_mutex_lock(&philo->mutex[philo->id % philo->vars->number_philo]);
        print(philo, real_time(philo), "has taken a fork");
        print(philo, real_time(philo), "is eating");
        philo->ate++;
        if (philo->ate == philo->vars->number_of_meals)
            philo->vars->total_meals++;
        usleep(philo->vars->time_to_eat * 1000);
        philo->last_meal = get_time();
        pthread_mutex_unlock(&philo->mutex[philo->id - 1]);
        pthread_mutex_unlock(&philo->mutex[philo->id % philo->vars->number_philo]);
        print(philo, real_time(philo), "is sleeping");
        usleep(philo->vars->time_to_sleep * 1000);
        print(philo, real_time(philo), "is thinking");
    }
    return (0);
}

void    check_rountine(t_philo *philo, t_philo_vars *vars)
{
    int i;

    i = 0;
    while (1)
    {
        if (philo[i].vars->total_meals == philo[i].vars->number_philo)
        {
            destroy_mutex(philo);
            free_params(philo, philo->mutex, vars);
            return ;
        }
        if (get_time() - philo[i].last_meal
            > (unsigned long)vars->time_to_die)
        {
            usleep(100);
            pthread_mutex_lock(philo->print);
            printf("%lums   %d died", real_time(philo), philo->id);
            destroy_mutex(philo);
            free_params(philo, philo->mutex, vars);
            return ;
        }
        i = (i + 1) % vars->number_philo;
        usleep(500);
    }
}

int main(int ac, char **av)
{
    int                 i;
    t_philo             *philo;
    t_philo_vars        *vars;
    pthread_t           *thread;

    printf("Entrou\n");
    if (ac < 5 || ac > 6)
        return (exit_error());
    vars = (t_philo_vars *)malloc(sizeof(t_philo_vars));
    if (init_vars(vars, av) == 1)
        return (free_params(0, 0, vars));
    philo = (t_philo *)malloc(sizeof(t_philo) * vars->number_philo); 
    
    if (init_program(philo, vars) == 1)
        return (1);
    thread = (pthread_t *)malloc(sizeof(pthread_t) * vars->number_philo);
    i = -1;
   
    while (++i < philo->vars->number_philo)
    {
       
        pthread_create(&thread[i], NULL, routine, philo + 1);
        usleep(100);
    }
    check_rountine(philo, vars);
    free(thread);
    return (0);
}