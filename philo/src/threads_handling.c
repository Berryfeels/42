/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:24:35 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/10/11 15:52:35 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_join_threads(pthread_t *philo, t_args *data)
{
	int	i;

	i = 0;
	while(i < data->number_of_philosophers)
	{
		pthread_join( philo[i++], NULL);//it is like the wait for processes
	}
}

void *routine(void *args)
{
	t_args *data =(t_args *) args; 
// 	timestamp_in_ms X has taken a fork
// timestamp_in_ms X is eating
// timestamp_in_ms X is sleeping
// timestamp_in_ms X is thinking
// timestamp_in_ms X died

	printf("%li %i has taken a fork\n", get_elapsed_time(data), data->philo_id);
	
	printf("sleeping demo\n");
	return NULL;
}

void	ft_threads(t_args *data)
{
	pthread_t philo[data->number_of_philosophers];
	int i;
	
	i = 0;
	
	while (i <= data->number_of_philosophers)//initialize the threads
	{
		data->philo_id = i + 1;
		if (pthread_create(&philo[i], NULL, routine, &data) != 0)
				ft_exit_error(EXIT_ERROR_THREAD); //Error check
		printf("Philli[%i] was created\n", i);
		i++;
	}
	ft_join_threads(philo, data);
}