#include "minilibx/mlx.h"
#include <stdlib.h>

#define HEIGHT 400
#define WIDTH 400

int main ()
{
		
	void *mlx_ptr;
	void *mlx_window;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (1);
	mlx_window = mlx_new_window (mlx_ptr, WIDTH, HEIGHT, "new");

	mlx_loop(mlx_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (0);
}