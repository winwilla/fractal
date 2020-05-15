#include "fractol.h"

void	draw_burning_ship(t_fractal *fractal)
{
	t_params	p;

	p.y = fractal->start_line;
	while (p.y < fractal->end_line)
	{
		p.x = 0;
		while (p.x < fractal->image.width)
		{
			p.c.re = fractal->min.re + p.x * fractal->d.re;
			p.c.im = fractal->max.im - p.y * fractal->d.im;
			p.z = new_complex(0.0, 0.0);
			p.i = -1;
			while (++p.i < fractal->max_iter && sqrt(complex_abs(p.z)) <= 16)
			{
				p.t = p.z;
				p.z.re = p.t.re * p.t.re - p.t.im * p.t.im + p.c.re;
				p.z.im = -2 * fabs(p.t.re * p.t.im) + p.c.im;
			}
			draw_pixel(p.x, p.y, choose_color_scheme(p.i, fractal, p.z),
																	fractal);
			p.x++;
		}
		p.y++;
	}
}
