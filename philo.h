/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomendes <jomendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:54:27 by jomendes          #+#    #+#             */
/*   Updated: 2024/05/07 16:37:11 by jomendes         ###   ########.fr       */
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

// parsing.c

int							check_args(char **av);
int							ft_atol(char *str);
unsigned long 				get_time(void);
unsigned long 				real_time(t_philo_vars *philo);

// init_program.c

int							init_vars(t_philo_vars *philo, char **av);
void						assing_param(t_philo *philo, t_philo_vars *vars, pthread_mutex_t *vars, 
										pthread_mutex_t *mutex);
int							init_program(t_philo *philo, t_philo_vars *vars);
int							free_params(t_philo *philo);

typedef struct 		s_philo_vars
{
	int						number_philo;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						number_of_meals;
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

#endif