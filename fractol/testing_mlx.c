#include "./minilibx/mlx.h"
#include <stdlib.h>

#define HEIGHT 500
#define WIDTH 500
#define MALLOC_ERROR 1

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	return (0);
}

int main ()
{
	void *mlx_connection;
	void *mlx_window;

	mlx_connection = mlx_init();
	if (mlx_connection == NULL)
		return (MALLOC_ERROR); 
	mlx_window = mlx_new_window(mlx_connection, HEIGHT, WIDTH, "test");
	for (int y = 0; y < WIDTH; ++y)
	{
			for (int x = 0; x < HEIGHT; ++x)
			{
				mlx_pixel_put (mlx_connection, mlx_window, x, y, 0xff0000);
			}
	}
	if(mlx_window == NULL)
	{
		mlx_destroy_display(mlx_connection);
		free (mlx_connection);
		return (MALLOC_ERROR);
	}
	mlx_loop(mlx_connection);
	mlx_key_hook(mlx_connection, key_hook, &vars);

	if (int	key_hook(int keycode, t_vars *vars))
	{	
		mlx_destroy_display(mlx_connection);
		free (mlx_connection);
		return (MALLOC_ERROR);
		return (0);
	}

	
	return 0;
}
