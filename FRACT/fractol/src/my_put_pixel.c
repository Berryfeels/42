/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:24:44 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/04/10 20:32:20 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"



/*
 * IMAGE DATA
 * 
 ***WHY LINE_LEN? 
 * Can i just make SIDE_LEN * 4 to get the bytes into a line? Nope...due to...
 *
 * 								👀 Alignment optimization 👀
 * ~https://www.youtube.com/watch?v=iz958I8Xb2g&list=PLc4DnsRQbs6ae27mFDLz5aJo6_p9uf3m-&index=51
 *
 * For instance, let's say an image is 5 pixels wide, and each pixel takes 4 bytes 
 * (assuming 32 bits or 4 bytes per pixel for colors). So, you'd expect the image width 
 * in memory to be 20 bytes. But due to the way memory alignment works, the line_length 
 * could be 24 bytes or any other suitable value that the system deems efficient.
 *
 * TL;DR
 * 		"When working with image data in memory, especially in graphics programming, 
 * 				it's crucial to be aware of how the data is aligned and stored"
 *
 ***ENDIAN? 
 *  Consider the number 0x12345678:

	In Big-Endian: It's stored as 12 34 56 78 in memory.

	In Little-Endian: It's stored as 78 56 34 12 in memory.

	How does this apply to graphics and MiniLibX?
	When we're dealing with colors in graphics, we often represent them using 
	multiple bytes. For example, ARGB format uses 4 bytes to represent a color: 
	one byte each for the Alpha, Red, Green, and Blue components.
	If your system is Big-Endian, the ARGB value 0x12345678 would mean the alpha value
	is 0x12, the red value is 0x34, the green value is 0x56, and the blue value is 0x78.
		DO WE CARE? NO. 👀
	Direct Memory Manipulation: While the endian value becomes critical when doing 
	direct memory manipulation byte-by-byte. 
	The manipulation is done using (unsigned int *) for the entire color value, namely the pixel. 
	This approach abstracts away the need for us to consider individual byte order for each color channel, thank god.
*/


/*
 * Plot in a 2D image the pixel
*/
void	my_pixel_put(t_img *img, int x, int y, int color)
{
	t_vars	*vars;
	t_img	*img;
	int		offset;

	//🚨 Line len is in bytes. WIDTH 800 len_line ~3200 (can differ for alignment)
	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));	

	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}

/*
 * 🔥 my_pixel_put
*/
void	color_screen(t_vars *vars, int color)
{
	t_vars	*vars;
	
	for (int y = 0; y < HEIGHT; ++y)	
	{
		for (int x = 0; x < WIDTH; ++x)
		{
			/*
			 * This function is much faster than the library one🏻
			 * 	~Buffer in the image and push only when ready-> No flickering effect
			*/
			my_pixel_put(&vars->image, x, y, color);
		}
	}
}

/*
 * This time i plug color in hexadecimal directly
 * easy vanilla
*/
int	f(int keysym, t_vars *vars)
{

	if (keysym == XK_r)
	{
		color_screen(vars, 0xff0000);
	}
	else if (keysym == XK_g)
	{
		color_screen(vars, 0xff00);
	}
	else if (keysym == XK_b)
	{
		color_screen(vars, 0xff);
	}	
	else if (keysym == XK_Escape)
		exit(1);

	// push the READY image to window
	// the last parameters are the offset image-window
	mlx_put_image_to_window(vars->mlx,
							vars->win, 
							vars->image.img_ptr, 
							0, 0);

	return 0;
}