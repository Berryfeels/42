->/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:25:31 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/04/10 23:17:51 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

 
// Pixel array

 
void mandelbrot(t_data *data, t_mandel *t_mandel)
{
	int p[HEIGHT][WIDTH];

	t_mandel->limit = 100.0;
    t_mandel->real_centre = 0; // to connect to position mouse
    t_mandel->imag_centre = 0.5;//to connect to position mouse
    t_mandel->real_range = 0.5;// to connect to zoom
    t_mandel->cre_min = t_mandel->real_centre - 0.5*t_mandel->real_range;
    t_mandel->cre_max = t_mandel->real_centre + 0.5*t_mandel->real_range;
    t_mandel->cim_min = t_mandel->imag_centre - 0.5*HEIGHT*t_mandel->real_range/WIDTH;
    t_mandel->cim_max = t_mandel->imag_centre + 0.5*HEIGHT*t_mandel->real_range/WIDTH;



   t_mandel->coordinate_y = 0;
	while (t_mandel->coordinate_y < HEIGHT) 
	{
    // Initialize x-coordinate
   		t_mandel->coordinate_x = 0;
   		while (t_mandel->coordinate_x < WIDTH) 
		{
        	// Calculate c value for this pixel
        	t_mandel->cre = t_mandel->cre_min + (t_mandel->cre_max - t_mandel->cre_min) * t_mandel->coordinate_x / (double) WIDTH;
        	t_mandel->cim = t_mandel->cim_min + (t_mandel->cim_max - t_mandel->cim_min) * t_mandel->coordinate_y / (double) HEIGHT;

        // Iterate for current c value
        	p[t_mandel->coordinate_x][t_mandel->coordinate_y] = 255;
        	t_mandel->zre = 0;
        	t_mandel->zim = 0;
       		 while (fabs(t_mandel->zre) < t_mandel->limit && fabs(t_mandel->zim) < t_mandel->limit && p[t_mandel->coordinate_y][t_mandel->coordinate_x] > 0) 
			{
           		t_mandel->zre_next = t_mandel->zre * t_mandel->zre - t_mandel->zim * t_mandel->zim + t_mandel->cre;
           		t_mandel->zim_next = 2 * t_mandel->zre * t_mandel->zim + t_mandel->cim;
            	t_mandel->zre = t_mandel->zre_next;
            	t_mandel->zim = t_mandel->zim_next;
            	p[t_mandel->coordinate_y][t_mandel->coordinate_x] *= 0.98;
				my_pixel_put(data, t_mandel->coordinate_y, t_mandel->coordinate_x)
       		}

        // Increment x-coordinate
        	t_mandel->coordinate_x++;
   	
		}

    	// Increment y-coordinate
    	t_mandel->coordinate_y++;
	}
}