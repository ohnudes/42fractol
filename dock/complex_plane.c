
#include <stdio.h>

typedef struct	s_complex
{
	double	rl;
	double	im;
}				t_complex;

int	main(void)
{
	// constant
	t_complex	z;
	// point
	t_complex	c;
	double		tmp_real;

	z.rl = 0;
	z.im = 0;
	c.rl = 0.1;
	c.im = 0.2;


	// general formula
	// z = z^2 + c
		// (real * im)^2 = a^2 + 2ab(im) + b(im)^2
		// given im^2 = -1,
		// a^2 - b^2 + 2ab(im)

	for (int i = 0; i < 42; ++i)
	{
		tmp_real = (z.rl * z.rl) - (z.im * z.im);
		z.im = 2 * z.rl * z.im;
		z.rl = tmp_real;

		// adding
		z.rl += c.rl;
		z.im += c.im;

		printf("iteration %d	real %f	im %f\n", i, z.rl, z.im);
	}
	return (0);
}
