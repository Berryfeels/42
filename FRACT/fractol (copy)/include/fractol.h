/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:54:47 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/04/10 23:22:56 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "minilibx/mlx.h"
# include <stdio.h>
# include "libft/libft.h"
# include <X11/keysym.h>

# define ERROR_MESSAGE 1
# define HEIGHT 500
# define WIDTH 900
# define MALLOC_ERROR 1


//WINDOW STRUCTURE
typedef struct s_vars {
	void *mlx;
	void *win;
}	t_vars;

typedef struct s_data
{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		endian;
	int		line_length;
}				t_data;

//MANDELBROT SET STRUCTURE. Determined by a complex number (determined by one real number and one imaginary number, Ex: 5, 6i)
//determined by the formula f(z) =z^z + c where z and c are complex numbeers.
 typedef struct s_mandelbrot
	{
		int coordinate_x;
		int	coordinate_y;
    	double real_centre, imag_centre, real_range;
    	double cre, cim, cre_min, cre_max, cim_min, cim_max;
    	double zre, zim, zre_next, zim_next;
    	double limit;
		}	t_mandel;

//MOUSE POSITION FOR ZOOM IMPLEMENTATION
typedef struct s_mouse_position {

	int x;
	int y;
	
}	t_mouse;

//COLORS
#define WHITE       0xFFFFFF   // White
#define BLACK       0x000000   // Black
#define RED         0xFF0000   // Red
#define GREEN       0x00FF00   // Green
#define BLUE        0x0000FF   // Blue
#define YELLOW      0xFFFF00   // Yellow
#define CYAN        0x00FFFF   // Cyan
#define MAGENTA     0xFF00FF   // Magenta
#define ORANGE      0xFFA500   // Orange
#define PURPLE      0x800080   // Purple
#define PINK        0xFFC0CB   // Pink
#define TEAL        0x008080   // Teal
#define LIME        0x00FF00   // Lime
#define AQUA        0x00FFFF   // Aqua
#define INDIGO      0x4B0082   // Indigo

// Psychedelic Colors
#define NEON_PINK   0xF535AA   // Neon Pink
#define ELECTRIC_BLUE 0x7DF9FF // Electric Blue
#define LASER_LEMON 0xFFFF54   // Laser Lemon
#define PSYCHEDELIC_PURPLE 0xDF00FF // Psychedelic Purple
#define ACID_GREEN  0xB0BF1A   // Acid Green
#define RAVE_RED    0xFF006E   // Rave Red
#define TRIPPY_TEAL 0x00FFC2   // Trippy Teal
#define GROOVY_GREEN 0x9ACD32  // Groovy Green
#define FUNKY_FUCHSIA 0xFF007F // Funky Fuchsia
#define BLAZING_YELLOW 0xFFFF33 // Blazing Yellow

//FUNCTIONS
int	launch_window(t_vars *vars, t_data *data);
int	esc_close(int keycode, t_vars *vars);
int	click_close(t_vars *vars);
int	handle_no_event(void);
int	create_image(t_vars *vars, t_data *data);
void	color_screen(t_data *data, int color);
void	my_pixel_put(t_data *data, int x, int y, int color);
void mandelbrot(t_data *data, t_mandel *t_mandel);

#endif 