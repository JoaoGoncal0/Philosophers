/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomendes <jomendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:54:23 by jomendes          #+#    #+#             */
/*   Updated: 2024/05/07 16:36:23 by jomendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

unsigned long real_time(t_philo_vars *philo)
{
	return (get_time() - philo->time_now);
}

int main(int ac, char **av) 
{
	pthread_t tid1, tid2;

    if (ac < 5 || ac > 6) 
	{
        printf("Wrong number of augments\n");
        return 1;
    }
    t_philo_vars philo;
    if (init_vars(&philo, av) == 1) 
	{
        printf("Invalid arguments.\n");
        return 1;
    }
    printf("Number of philosophers: %d\n", philo.number_philo);
    printf("Time to die: %d\n", philo.time_to_die);
    printf("Time to eat: %d\n", philo.time_to_eat);
    printf("Time to sleep: %d\n", philo.time_to_sleep);
    if (ac == 6) {
        printf("Number of times each philosopher must eat: %d\n", philo.number_of_meals);
    }
	int time = get_time();
	printf ("time : %d milliseconds\n", time);
	t_philo_vars *p = &philo;
	int time_now = real_time(p);
	printf ("Real time : %d milliseconds\n", time_now);
	free(p);
    return (0);
}
