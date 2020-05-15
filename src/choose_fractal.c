#include "fractol.h"

void			choose_fractal(t_fractal *fractal)
{
	if (fractal->type == JULIA)
		draw_julia(fractal);
	else if (fractal->type == FROSTY)
		draw_frosty(fractal);
	else if (fractal->type == MANDELBROT)
		draw_mandelbrot(fractal);
	else if (fractal->type == RADIOLARIA)
		draw_radiolaria(fractal);
	else if (fractal->type == SPIDER)
		draw_spider(fractal);
	else if (fractal->type == BURNING_SHIP)
		draw_burning_ship(fractal);
	else if (fractal->type == NEWTON)
		draw_newton(fractal);
	else if (fractal->type == NOVA)
		draw_nova(fractal);
	else if (fractal->type == LEAF)
		draw_fern_leaf(fractal);
	else if (fractal->type == PITER)
		draw_piter(fractal);
	else if (fractal->type == CLIFFORD)
		draw_klifford(fractal);
}

t_fractal_cl	init_input(t_fractal *fractal)
{
	t_fractal_cl input;

	input.type = fractal->type;
	input.max_iter = fractal->max_iter;
	input.min.re = fractal->min.re;
	input.min.im = fractal->min.im;
	input.max.re = fractal->max.re;
	input.max.im = fractal->max.im;
	input.k.re = fractal->k.re;
	input.k.im = fractal->k.im;
	input.d.re = fractal->d.re;
	input.d.im = fractal->d.im;
	input.color = fractal->color;
	fractal->cl.global_work_size = WIDTH * HEIGHT;
	fractal->cl.local_work_size = 64;
	fractal->cl.iter = 0;
	input.r.f_red = fractal->random.f_red;
	input.r.f_green = fractal->random.f_green;
	input.r.f_blue = fractal->random.f_blue;
	input.r.p_red = fractal->random.p_red;
	input.r.p_blue = fractal->random.p_blue;
	input.r.p_green = fractal->random.p_green;
	input.r.width = fractal->random.width;
	input.r.center = fractal->random.center;
	return (input);
}
