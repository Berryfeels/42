/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:57:31 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/10/11 15:44:35 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void arg_data_init (t_args *data, char **argv)
{
	data->number_of_philosophers = ft_atoi(argv[1]);
	if (data->number_of_philosophers < 2)
		ft_exit_error(EXIT_ERROR_TOO_FEW_PHILOSOPHERS);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->philo_id = 0;
	if (argv[5])
		data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else 
		data->number_of_times_each_philosopher_must_eat = 0;
	gettimeofday(&data->starting_time, NULL);
}