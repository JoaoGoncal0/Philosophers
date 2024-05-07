/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomendes <jomendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:17:53 by jomendes          #+#    #+#             */
/*   Updated: 2024/05/07 16:31:59 by jomendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// number of threads = number of philosophers
// each philosopher will create another thread just to check if they are dead
// each philo will run the philo routine function 
// the observer will run the monitor function to see if somebody dies

// Philo Routine()
//
//	Infinite loop breaks when dead_flag = 1
//	
//	Philo ->  Eat -> Sleep or Think 
//
//	Thinking -> printf("X is thinking") X = number of the philo
//	
//	Sleep ->  Sleep the length of the input insert by the user in av[4]
//				Use ft_usleep ()
//
//	Eat ->	  Lock the right fork using p_mutex_lock
//				printf("X has taken a fork")
//			  Lock the left 
//				same printf
//			  Incrementar o numero de refeicoes ate ser igual ao av[5]
//			  Use ft_usleep for the lenght of av[3] after unlock the mutexes
//				
//	Monitor ()
//
//	Infinite loop
//	
//	2 checks:
//
//	check number 1 -> If a philo dies / time_to_died < time_to_eat + time_to_sleep com um numero par de philos
//										time_to_died < 2 vezes o time_to_eat + time_to_sleep com numero impar de philos
//						
//	check number 2 -> If they all ate the number of meals in av[5]
//
//	se todos os philosofos acabaram de comer av[5] vezes o programa acaba dead_flag = 1 interromper os loops das threads
//	se alguem morrer o programa acaba / dead_flag = 1 e interrompe o loop de todas as threads(philos)
//	
//	Ninguem morre enquanto come!
//
//	
//	No final destruir todas as mutexes e dar os frees necessarios 
//

#include "philo.h"

int main(int ac, char **av) 
{
    if (ac < 5 || ac > 6) 
	{
        printf("Wrong number of arguments\n");
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
    if (ac == 6) 
        printf("Number of times each philosopher must eat: %d\n", philo.number_of_meals);
		
    t_philo *philos = malloc(sizeof(t_philo) * philo.number_philo);
    if (!philos) 
	{
        printf("Failed to allocate memory for philosophers.\n");
        return 1;
    }
    pthread_mutex_t print_mutex;
    pthread_mutex_init(&print_mutex, 0);
    assign_param(philos, &philo, philo.number_philo, &print_mutex);
    for (int i = 0; i < philo.number_philo; ++i) {
        printf("Philosopher %d: ate=%d, id=%d, vars=%p, mutex=%p, print_mutex=%p\n",
               i+1, philos[i].ate, philos[i].id, philos[i].vars, philos[i].mutex, philos[i].print);
    }
    free(philos);
    return 0;
}
