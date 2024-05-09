/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomendes <jomendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:54:27 by jomendes          #+#    #+#             */
/*   Updated: 2024/05/08 17:11:47 by jomendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct 		s_philo_vars
{
	int						number_philo;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						number_of_meals;
	int						total_meals;
	unsigned long			time_now;
}					t_philo_vars;

typedef struct 		s_philo
{
	int						ate;
	int						id;
	t_philo_vars			*vars;
	pthread_mutex_t			*mutex;
	pthread_mutex_t			*print;
	unsigned long			last_meal;
}					t_philo;

// parsing.c

int							check_args(char **av);
int							ft_atol(char *str);
unsigned long 				get_time(void);
unsigned long 				real_time(t_philo *philo);

// init_program.c

int							init_vars(t_philo_vars *philo, char **av);
void						assing_param(t_philo *philo, t_philo_vars *vars, pthread_mutex_t *mutex, 
										pthread_mutex_t *print);
int							init_program(t_philo *philo, t_philo_vars *vars);

// free_functions.c

int 						exit_error(void);
int 						free_params(t_philo *philo, pthread_mutex_t *mutex, 
										t_philo_vars *vars);
void   						 destroy_mutex(t_philo *philo);

// main.c 

void   						print(t_philo *philo, unsigned long time, char *action);
void    					*routine(void *p);
void   						check_rountine(t_philo *philo, t_philo_vars *vars);
int							main(int ac, char **av);

#endif