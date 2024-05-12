#include "philo.h"

int exit_error(void)
{
    printf("Wrong params\n");
    return (1);
}

int free_params(t_philo *philo, pthread_mutex_t *mutex, t_philo_vars *vars)
{
    if (mutex)
        free(mutex);
    if (vars)  
        free(vars);
    if (philo)
        free(philo);
    return (1);
}

void    destroy_mutex(t_philo *philo)
{
    int i;

    i = 0;
    while (i < philo->vars->number_philo)
        pthread_mutex_destroy(&philo->mutex[i++]);
}

void free_threads(pthread_t *threads, int number_philo)
{
    if (!threads)
        return;

    int i = 0;
    while (i < number_philo) {
        pthread_join(threads[i], NULL);
        i++;
    }
    free(threads); 
}
