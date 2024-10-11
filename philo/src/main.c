/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:07:06 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/10/11 15:28:52 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main (int argc, char **argv)
{
	t_args *data;

	data = malloc(sizeof(t_args));
	if(!data)
		ft_exit_error(EXIT_ERROR_STRUCT_INIT);	
	ft_error_check(argc, argv);
	arg_data_init (data, argv);
	ft_threads(data);
	free (data);
	return 0;
}