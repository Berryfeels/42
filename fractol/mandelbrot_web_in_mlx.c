#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./minilibx/mlx.h"
 
#define W 1920	
#define H 1080
#define HEIGHT 1920
#define WIDTH 1080
#define MALLOC_ERROR 1
 
// Pixel array
int p[H][W];
 
int main(int argc, char *argv[])
{
    int x, y;
    double real_centre, imag_centre, real_range;
    double cre, cim, cre_min, cre_max, cim_min, cim_max;
    double zre, zim, zre_next, zim_next;
    double limit = 100.0;
	void *mlx_ptr;
	void *mlx_window;
     
    // Parse command line arguments
    if (argc != 5)
    {
        printf("Usage: mandelbrot REAL_CENTRE IMAG_CENTRE REAL_RANGE FILENAME\n");
        return 0;
    }

    real_centre = atof(argv[1]);
    imag_centre = atof(argv[2]);
    real_range = atof(argv[3]);
    cre_min = real_centre - 0.5*real_range;
    cre_max = real_centre + 0.5*real_range;
    cim_min = imag_centre - 0.5*H*real_range/W;
    cim_max = imag_centre + 0.5*H*real_range/W;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (1);
	mlx_window = mlx_new_window (mlx_ptr, WIDTH, HEIGHT, "new");
     
    // Calculate pixel values
    for (y=0;y<H;++y)
    {
        for (x=0;x<W;++x)
        {
            // Calculate c value for this pixel
            cre = cre_min + (cre_max-cre_min)*x/(double)W;
            cim = cim_min + (cim_max-cim_min)*y/(double)H;
             
            // Iterate for current c value
            p[y][x] = 255;
            zre = 0; zim = 0;
            while (fabs(zre) < limit && fabs(zim) < limit && p[y][x] > 0)
            {
                zre_next = zre*zre - zim*zim + cre;
                zim_next = 2*zre*zim + cim;
                zre = zre_next;
                zim = zim_next;
                p[y][x] *= 0.98;
            }  
        }
    }

	mlx_loop(mlx_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);     
    return 0;
}