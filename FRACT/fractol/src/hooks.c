/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:09:32 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/04/08 14:02:51 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	handle_no_event(void)
{
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

int click_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	exit (0);
	return(0);
}

int	esc_close(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		//printf("hello: %p", vars->mlx);
		
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		exit (0);
		return(0);
	
		
	}
	printf("%d\n", keycode);
	printf("%p\n", vars);
	return 0;
}

//mlx_mouse_hook(vars.win, mouse_hook, &vars);