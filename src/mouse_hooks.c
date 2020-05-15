#include "fractol.h"

/*
** JULIA MOTION
*/

int		julia_motion(int x, int y, t_fractal *fractal)
{
	if (fractal->type == JULIA && fractal->julia_motion)
	{
		fractal->k = new_complex(fractal->min.re + x * fractal->d.re,
							fractal->max.im - y * fractal->d.im);
		draw_fractal(fractal);
	}
	return (0);
}

int		left_mouse_press(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (fractal->type == JULIA && button == MOUSE_LEFT)
	{
		fractal->julia_motion = !(fractal->julia_motion);
		draw_fractal(fractal);
	}
	return (0);
}

/*
** ZOOM FOR MOUSE POINTER
*/

int		zoom_wheel(int button, int x, int y, t_fractal *fractal)
{
	t_complex	mouse;
	t_complex	delta;
	double		zoom;

	if (button == MOUSE_UP || button == MOUSE_DOWN)
	{
		mouse = new_complex(fractal->min.re + x * fractal->d.re,
							fractal->max.im - y * fractal->d.im);
		zoom = (button == MOUSE_DOWN) ? 1.2 : 0.8;
		fractal->min = complex_mult_num(fractal->min, zoom);
		fractal->max = complex_mult_num(fractal->max, zoom);
		fractal->d = new_complex(
			(fractal->max.re - fractal->min.re) / fractal->image.width,
			(fractal->max.im - fractal->min.im) / fractal->image.height);
		delta = complex_mult_num(mouse, 1 - zoom);
		fractal->max = complex_add(fractal->max, delta);
		fractal->min = complex_add(fractal->min, delta);
		draw_fractal(fractal);
	}
	return (0);
}
