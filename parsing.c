/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomendes <jomendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:54:23 by jomendes          #+#    #+#             */
/*   Updated: 2024/05/06 16:10:03 by jomendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ./philo 						10            50 			 10				 10				4
	
					//number_philo      time_to_die	 time_to_eat	time_to_sleep  OPCIONAL number_REFEICOES

#include "philo.h"

int	check_args(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_atol(char *str)
{
	int	i;
	long	result;
	int	signal;

	i = 0;
	result = 0;
	signal = 1;
	while (str[i] >= 9 && str[i] <= 13 || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * signal);
}

int	init_vars(t_philo_vars *vars, char **av)
{
	if (check_args(av) == 1)
		return (1);
	vars->number_philo = ft_atol(av[1]);
	vars->time_to_die = ft_atol(av[2]);
	vars->time_to_eat = ft_atol(av[3]);
	vars->time_to_sleep = ft_atol(av[4]);
	if (av[5])
	{
		vars->number_meals = ft_atol(av[5]);
		if (vars->number_meals <= 0)
			return (1);
	}
	else
		vars->number_meals = -1;
	if (vars->number_philo <= 0 ||
		vars->time_to_die <= 0 ||
		vars->time_to_eat <= 0 ||
		vars->time_to_sleep <= 0)
		return (1);
	return (0);
}

unsigned long get_time(void)
{
	struct timeval	time;
	unsigned long	sec;
	unsigned long	micro_sec;
	unsigned long	total;

	gettimeofday(&time, NULL);
	sec = (time.tv_sec * 1000);
	micro_sec = (time.tv_usec / 1000);
	total = (sec + micro_sec);
	return (total);
}

int count = 0;
pthread_mutex_t lock;

void	*routine(void *av)
{
	int i;
	(void) *av;
	
	i = -1;
	while (++i < 1000)
	{
		pthread_mutex_lock(&lock);
		count++;
		pthread_mutex_unlock(&lock);
	}
	return (NULL);
}



int main(int ac, char **av) 
{
	pthread_t tid1, tid2;

    if (ac < 5 || ac > 6) 
	{
        printf("Wrong number of augments\n");
        return 1;
    }
    t_philo_vars vars;
    if (init_vars(&vars, av) == 1) 
	{
        printf("Invalid arguments.\n");
        return 1;
    }
    printf("Number of philosophers: %d\n", vars.number_philo);
    printf("Time to die: %d\n", vars.time_to_die);
    printf("Time to eat: %d\n", vars.time_to_eat);
    printf("Time to sleep: %d\n", vars.time_to_sleep);
    if (ac == 6) {
        printf("Number of times each philosopher must eat: %d\n", vars.number_meals);
    }
	int time = get_time();
	printf ("Total : %d milliseconds\n", time);
	
	pthread_mutex_init(&lock, NULL);
  	pthread_create(&tid1, NULL, &routine, NULL);
  	pthread_create(&tid2, NULL, &routine, NULL);
	
  	pthread_join(tid1, NULL);
  	pthread_join(tid2, NULL);
  	pthread_mutex_destroy(&lock);
  	printf("cont: %d\n", count);
    return (0);
}
