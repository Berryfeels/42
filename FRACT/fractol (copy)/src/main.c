/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:41:48 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/04/10 21:32:34 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/libft/libft.h"


int main (int argc, char **argv)
{
	t_vars vars;
	t_data data;
	
	if (argc == 2 && !ft_strncmp("Mandelbrot", argv[1], 10))
		launch_window(&vars, &data);
	else 
		return (write(1, "no no no", 8), 0);
	return (0);
    
	}
