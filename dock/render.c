
#include "fractal.h"

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	size_t		i;
	double		tmp_real;

	z.x = 0.0;
	z.y = 0.0;
	c.x = map(x, -2, +2, 0, WIDTH);
	c.y = map(x, +2, -2, 0, HEIGHT);
	i = 0;
	while (i < 2)
	{
		// aiming for z = z^2 + c
		z = sum_complex(square_complex(z), c);
		if (z.x * z.x + (z.y * z.y) > fractal->escape_value)
		{
			my_pixel_put();
			return ;
		}
	}
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
}
