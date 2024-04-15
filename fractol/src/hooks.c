/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:09:32 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/04/15 18:36:46 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void recentre_image(int x, int y, t_data *data)
{
    int new_x = x - WIDTH / 2;
    int new_y = y - HEIGHT / 2;

    // Update image display to show centered at new coordinates
    mlx_put_image_to_window(data -> mlx, data -> win, data -> img, new_x, new_y);
}

int mouse_event(int button, int x, int y, t_data *data)
{
	if (button == 4)
		data->zoom *= 0.95;
	else if (button == 5)
		data->zoom *= 1.05;
	else if (button == Button1)
	{
		recentre_image(x, y, data);
	}
	fractal_render(data);
	return (0);
}

int	key_handle(int keycode, t_data *data)
{
	printf("%d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free (data->mlx);
		exit (EXIT_SUCCESS);
	}
	else if (keycode == 65361)
	{
		data->shift_x += (0.1 * data->zoom);
	}
	else if (keycode == 65363)
	{
		data->shift_x -= (0.1 * data->zoom);
	}
	else if (keycode == 65362)
	{
		data->shift_y -= (0.1 * data->zoom);
	}
	else if (keycode == 65364)
	{
		data->shift_y += (0.1 * data->zoom);
	}
		else if (keycode == 65451)
	{
		data->iteration_times += 10;
	}
		else if (keycode == 65453)
	{
		data->iteration_times -= 10;
	}
	fractal_render(data);
	return 0;
}

int click_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	exit (0);
}

int	handle_no_event(void)
{
	return (0);
}