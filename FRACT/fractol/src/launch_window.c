/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:12:53 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/04/09 18:06:39 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int launch_window(t_vars *vars)
{
	
    vars->mlx = mlx_init();
    if (vars->mlx == NULL)
        return(MALLOC_ERROR);
		
    vars->win = mlx_new_window(vars->mlx, HEIGHT, WIDTH, "test");
    if (vars->win == NULL)
    {
		free(vars->win);
		return(MALLOC_ERROR);
    }
    for (int y = 0; y < WIDTH; ++y)
    {
        for (int x = 0; x < HEIGHT; ++x)
        {
            mlx_pixel_put(vars->mlx, vars->win, x, y, CYAN);
        }
    }
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
