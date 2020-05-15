#include "fractol.h"

static void	check_z(t_params *p, t_fractal *fract)
{
	t_color a;

	a = convert_color_int_to_rgb(BLACK);
	if (fabs(p->z.re) >= 300 || fabs(p->z.im) >= 10000)
		draw_pixel(p->x, p->y, choose_color_scheme(p->i, fract, p->z), fract);
	else
		draw_pixel(p->x, p->y, a, fract);
}

void		draw_radiolaria(t_fractal *fractal)
{
	t_params	p;

	p.y = fractal->start_line;
	while (p.y < fractal->end_line)
	{
		p.x = 0;
		while (p.x < fractal->image.width)
		{
			p.z.im = fractal->max.im - p.y * fractal->d.im;
			p.z.re = fractal->min.re + p.x * fractal->d.re;
			p.i = -1;
			while (++p.i < fractal->max_iter && complex_abs(p.z) <= 1000)
			{
				p.t = p.z;
				p.z.re = p.t.re * p.t.re * p.t.re -
											3 * p.t.re * p.t.im * p.t.im + 0.5;
				p.z.im = 3 * p.t.re * p.t.re * p.t.im -
											p.t.im * p.t.im * p.t.im;
			}
			check_z(&p, fractal);
			p.x++;
		}
		p.y++;
	}
}
