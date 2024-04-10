/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:12:53 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/04/10 22:14:45 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int launch_window(t_vars *vars, t_data *data)
{
	
    vars->mlx = mlx_init();
    if (vars->mlx == NULL)
        return(MALLOC_ERROR);
		
    vars->win = mlx_new_window(vars->mlx, HEIGHT, WIDTH, "test");
    if (vars->win == NULL)
    {
		mlx_destroy_display(vars->mlx);
		free(vars->win);
		return(MALLOC_ERROR);
    }
	data->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (data->img == NULL)
	 {
		mlx_destroy_display(vars->mlx);
		free(vars->win);
		return(MALLOC_ERROR);
    }
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	create_image(vars, data);
	mlx_loop_hook(vars->mlx, handle_no_event, vars);
	mlx_hook(vars->win, 17, 1L<<17, click_close, vars);
	mlx_hook(vars->win, 2, 1L<<0, esc_close, vars);
	//mlx_hook(vars->win, 4, int x_event, int x_mask, click_close, void *param);
	//mlx_hook(win.mlx, 4, int x_event, int x_mask, click_close, void *param);
    mlx_loop(vars->mlx); // Starting the main event loop
	
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	return(0);
}