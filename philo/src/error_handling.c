/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:58:22 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/10/11 15:44:36 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_exit_error(int error_type)
{
	if (error_type == EXIT_ERROR_ARGS)
	{
		printf("args must be 4 or 5 and different from 0");
		exit(EXIT_ERROR_ARGS);
	}
}

void ft_error_check(int argc, char **argv)
{
	int i;
	int number_of_philosophers;

	// if (argc < 5 || argc > 6)
	// 	ft_exit_error(EXIT_ERROR_ARGS);

	if(argc == 4)
		printf("argc 4");
	i = 1;
	while (i < argc)
	{
		if (argv[i++][0] == '0')
			ft_exit_error(EXIT_ERROR_ARGS);
	}
	if ((number_of_philosophers = ft_atoi(argv[1])) == -1)
		ft_exit_error(EXIT_ERROR_ARGS);
}