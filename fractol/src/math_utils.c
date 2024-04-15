/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:29:17 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/04/15 18:31:22 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*consider the formula for Mandelbrot is zn = zn^2 + c
z = real number + imaginary number -> (x+y)=(x+y)^2 + c -> (x+y)^2=(x)
real number = (x^2 - y^2) imag number = z*x*y*/

/* Julia set exchange c and z*/

double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

t_data   sum_complex(t_data z1, t_data z2)
{
    t_data   result;

    result.x = z1.x + z2.x;
    result.y = z1.y + z2.y;
    return result;
}

t_data   square_complex(t_data z)
{
    t_data   result;
    
    result.x = (z.x * z.x) - (z.y * z.y);
    result.y = 2 * z.x * z.y;
    return result;
}