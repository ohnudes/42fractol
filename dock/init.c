/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohadmin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:54:13 by ohadmin           #+#    #+#             */
/*   Updated: 2023/10/11 16:46:06 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

// INIT
// -mlx
// -listening events
// -hooks data

static void	malloc_error(void)
{
	perror("Problems with malloc\n");
	exit(EXIT_FAILURE);
}

void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations_def = 42;
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WIDTH,
			HEIGHT,
			fractal->name);
	if (fractal->mlx_window == NULL)
	{
		// LINUX mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		// LINUX mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr, 
			&fractal->img.bpp, 
			&fractal->img.line_len, 
			&fractal->img.endian);
//	events_init(fractal);
	data_init(fractal);
}
