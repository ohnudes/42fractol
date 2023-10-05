
#include "fractal.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)
			|| ac == 4 && !ft_strncmp(av[1], "julia", 5))
	{
		fractal.name = av[1];
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

/* create window structure - minilbx
	void	*mlx;
	void	*mlx_win;
	mlx = mlx_init();
	if (NULL == mlx)
		return (-1);
	mlx_win = mlx_new_window(mlx, 800, 600, "Hello world!");
	mlx_loop(mlx);

	mlx_destroy_display(mlx);
	free (mlx);
	return (0);
*/
