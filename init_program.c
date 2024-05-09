
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomendes <jomendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:38:51 by jomendes          #+#    #+#             */
/*   Updated: 2024/05/07 16:27:22 by jomendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_vars(t_philo_vars *vars, char **av)
{
	if (check_args(av) == 1)
		return (1);
	vars->time_now = get_time();
	vars->total_meals = 0;
	vars->number_philo = ft_atol(av[1]);
	vars->time_now = get_time();
	vars->time_to_die = ft_atol(av[2]);
	vars->time_to_eat = ft_atol(av[3]);
	vars->time_to_sleep = ft_atol(av[4]);
	if (av[5])
	{
		vars->number_of_meals = ft_atol(av[5]);
		if (vars->number_of_meals <= 0)
			return (1);
	}
	else
		vars->number_of_meals = -1;
	if (vars->number_philo <= 0 ||
		vars->time_to_die <= 0 ||
		vars->time_to_eat <= 0 ||
		vars->time_to_sleep <= 0)
		return (1);
	return (0);
}

void	assing_param(t_philo *philo, t_philo_vars *vars, 
		pthread_mutex_t *mutex, pthread_mutex_t *print)
{
	int	i;

	i = 0;
	while (i < vars->number_philo)
	{
		philo[i].ate = 0;
		philo[i].id = i + 1;
		philo[i].vars = vars;
		philo[i].mutex = mutex;
		philo[i].print = print;
		i++;
	}
}

int	init_program(t_philo *philo, t_philo_vars *vars)
{
	int i;

	i = 0;
	if (!philo)
		free_params(philo, NULL, vars);
	philo->mutex = malloc(sizeof(pthread_mutex_t) * vars->number_philo);
	if (!philo->mutex)
		free_params(philo, philo->mutex, vars);
	while (i < vars->number_philo)
	{
		if (pthread_mutex_init(&philo->mutex[i++], NULL) != 0)
			free_params(philo, philo->mutex, vars);
		if (pthread_mutex_init(philo->print, NULL) != 0)
			free_params(philo, philo->mutex, vars);
	}
	assing_param(philo, vars, philo->mutex, philo->print);
	return (0);
}
