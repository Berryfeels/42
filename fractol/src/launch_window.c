/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:12:53 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/04/15 18:31:20 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int launch_window(t_data *data)
{
	data_init (data);
	fractal_render(data);
	//mlx_hook(vars->win, ..,.., zoom, vars);
    mlx_loop(data->mlx);
	// mlx_destroy_display(data->mlx);
	// free(data->mlx);
	return(0);
}