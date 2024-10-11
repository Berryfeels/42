/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:13:44 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/10/11 15:48:45 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPHILO_H
# define LIBPHILO_H

#include <pthread.h>
#include <printf.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> 
#include <sys/time.h>


/*MACRO*/
#define EXIT_ERROR_ARGS -1
#define EXIT_ERROR_THREAD -2
#define EXIT_ERROR_TOO_FEW_PHILOSOPHERS -3
#define EXIT_ERROR_STRUCT_INIT -4

/*ARGS STRUCT*/
typedef struct	s_args
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
	int philo_id;
	struct timeval starting_time;
}				t_args;

//****************/*FUNCTIONS*/********************//
//Error check//
void	ft_exit_error(int error_type);
void ft_error_check(int argc, char **argv);

//Utils//
int	ft_atoi(char *digit);
long get_elapsed_time(t_args *data);

//Struct initialization//
void arg_data_init (t_args *data, char **argv);

void	ft_join_threads(pthread_t *philo, t_args *data);
void	ft_threads(t_args *data);

# endif