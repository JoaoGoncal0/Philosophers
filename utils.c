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
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
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
	if ((result * signal) > INT_MAX || result * signal <= 0)
		return (1);
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

unsigned long real_time(t_info *info)
{
	return (get_time() - info->time_now);
}