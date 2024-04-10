/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:25:31 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/04/10 20:24:59 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

 
// Pixel array
int p[HEIGHT][WIDTH];
 
int mandelbrot(t_vars *vars, t_vars)
{
    typedef struct s_mandelbrot
	{
		int coordinate_x;
		int	coordinate_y;
    	double real_centre, imag_centre, real_range;
    	double cre, cim, cre_min, cre_max, cim_min, cim_max;
    	double zre, zim, zre_next, zim_next;
    	double limit = 100.0;
		}	t_mandel;

    t_mandel.real_centre = 0; // to connect to position mouse
    t_mandel.imag_centre = 0.5;//to connect to position mouse
    t_mandel.real_range = 0.5;// to connect to zoom
    t_mandel.cre_min = t_mandel.real_centre - 0.5*t_mandel.real_range;
    t_mandel.cre_max = t_mandel.real_centre + 0.5*t_mandel.real_range;
    t_mandel.cim_min = t_mandel.imag_centre - 0.5*H*t_mandel.real_range/W;
    t_mandel.cim_max = t_mandel.imag_centre + 0.5*H*t_mandel.real_range/W;


     
    // Calculate pixel values
    for (t_mandel.coordinate_y=0;t_mandel.coordinate_y<HEIGHT;++t_mandel.coordinate_y)
    {
        for (t_mandel.coordinate_x=0;t_mandel.coordinate_x<WIDTH;++t_mandel.coordinate_x)
        {
            // Calculate c value for this pixel
        	t_mandel.cre = t_mandel.cre_min + (t_mandel.cre_max-t_mandel.cre_min)*t_mandel.coordinate_x/(double)W;
        	t_mandel.cim = t_mandel.cim_min + (t_mandel.cim_max-t_mandel.cim_min)*t_mandel.coordinate_y/(double)H;
             
            // Iterate for current c value
            p[t_mandel.coordinate_x][t_mandel.coordinate_y] = 255;
            t_mandel.zre = 0; 
			t_mandel.zim = 0;
            while (fabs(t_mandel.zre) < t_mandel.limit && fabs(t_mandel.zim) < t_mandel.limit && p[t_mandel.coordinate_y][t_mandel.coordinate_x] > 0)
            {
                t_mandel.zre_next = t_mandel.zre*t_mandel.zre - t_mandel.zim*t_mandel.zim + t_mandel.cre;
                t_mandel.zim_next = 2*t_mandel.zre*t_mandel.zim + t_mandel.cim;
                t_mandel.zre = t_mandel.zre_next;
                t_mandel.zim = t_mandel.zim_next;
                p[t_mandel.coordinate_y][t_mandel.coordinate_x] *= 0.98;
				
            }  
        }
    }  
    return 0;
}