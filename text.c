/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomendes <jomendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:17:53 by jomendes          #+#    #+#             */
/*   Updated: 2024/05/08 11:34:10 by jomendes         ###   ########.fr       */
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

