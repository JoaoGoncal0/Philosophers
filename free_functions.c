#include "philo.h"

int exit_error(void)
{
    printf("Wrong params\n");
    return (1);
}

int free_params(t_philo *philo, pthread_mutex_t *mutex, t_philo_vars *vars)
{
    if (philo)
        free(philo);
    if (mutex)
        free(mutex);
    if (vars)  
        free(vars);
    return (1);
}

void    destroy_mutex(t_philo *philo)
{
    int i;

    i = 0;
    while (i < philo->vars->number_philo)
        pthread_mutex_destroy(&philo->mutex[i++]);
}
