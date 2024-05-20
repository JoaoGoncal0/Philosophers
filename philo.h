#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct  s_check
{
    int available;
    pthread_mutex_t mutex;
}               t_check;

typedef struct  s_philo
{
    int id;
    pthread_t   thread;
    int meals_count;
    int time_to_die;
    pthread_mutex_t state;
    t_check *r_fork;
    t_check *l_fork;
    t_info  *info;
}              t_philo;

typedef struct s_info
{
    int n_philos;
    int time_to_died;
    int time_to_eat;
    int time_to_sleep;
    int n_meals;
    unsigned long time_now;
    int dead;
    int meals_eaten;
    t_check *forks;
    t_philo *philos;
    pthread_mutex_t lock;
    pthread_mutex_t message;
}             t_info;
// utils.c

int             check_args(char **av);
int             ft_atol(char *str);
unsigned long   get_time(void);
unsigned long   real_time(t_info *info);

// init.c

void            init_forks(t_info *info);
int             init_program(char **av, t_info *info);
void            run_program(t_info *info);
void            finish_program(t_info *info);

#endif