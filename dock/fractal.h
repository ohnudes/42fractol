/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohadmin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:12:19 by ohadmin           #+#    #+#             */
/*   Updated: 2023/10/05 19:13:23 by ohadmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "./mlx_linux/mlx.h"
// to include: libft

# define ERROR_MESSAGE "PARAMETER ERROR:\nplease enter correct fractol parameter\n"
# define HEIGHT	800
# define WIDTH	800

#define BLACK		0x000000
#define WHITE		0xFFFFFF
#define PURPLE_1	0xA020F0
#define PURPLE_2	0x800080
#define PURPLE_3 	0x7B68EE
#define PURPLE_4 	0x9932CC
#define PURPLE_5 	0x8A2BE2
#define PURPLE_6 	0x9400D3
#define PURPLE_7 	0xBA55D3
#define PURPLE_8 	0x9932CC

typedef struct	s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

typedef struct	s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations_def;
}				t_fractal;

typedef struct	s_complex
{
	double	x;
	double	y;
}				t_complex;

// production steps
void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);

// MATH
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);
double		map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);

// RENDER

int			ft_strncmp(char *s1, char *s2, int n);
void		ft_putstr_fd(char *s, int fd);

#endif
