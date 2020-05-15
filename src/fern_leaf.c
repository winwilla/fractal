#include "fractol.h"

static void	count_top_of_leaf(t_coord *k)
{
	double newx;
	double newy;

	newx = 0.84 * k->x - 0.045 * k->y;
	newy = 0.045 * k->x + 0.86 * k->y + 1.6;
	k->x = newx;
	k->y = newy;
	k->c = 1;
}

static void	count_left_leaf(t_coord *k)
{
	double newx;
	double newy;

	newx = 0.25 * k->x - 0.26 * k->y;
	newy = 0.23 * k->x + 0.25 * k->y + 1.6;
	k->x = newx;
	k->y = newy;
	k->c = 2;
}

static void	count_right_leaf(t_coord *k)
{
	double newx;
	double newy;

	newx = -0.135 * k->x + 0.28 * k->y;
	newy = 0.26 * k->x + 0.245 * k->y + 0.44;
	k->x = newx;
	k->y = newy;
	k->c = 3;
}

static void	count_color_leaf(t_fractal *fractal, t_coord k)
{
	t_color a;
	int		i;
	int		j;

	i = (int)(fractal->start_point_leaf.x - 10 + 90 * k.x * fractal->zoom);
	j = (int)(fractal->start_point_leaf.y - 90 * k.y * fractal->zoom);
	if (k.c == 1)
		a = convert_color_int_to_rgb(GREEN);
	else if (k.c == 2)
		a = convert_color_int_to_rgb(FOREST_GREEN);
	else if (k.c == 3)
		a = convert_color_int_to_rgb(DARK_GREEN);
	else
		a = convert_color_int_to_rgb(GREEN);
	if (i < 1000 && j < 1000 && i > 0 && j > 0)
		draw_pixel(i, j, a, fractal);
}

void		draw_fern_leaf(t_fractal *fractal)
{
	t_coord	k;
	int		i;
	int		rand_num;

	k.x = 1.0;
	k.y = 0.0;
	i = -1;
	while (++i < fractal->max_iter)
	{
		rand_num = rand();
		if (rand_num < 0.85 * RAND_MAX)
			count_top_of_leaf(&k);
		else if (rand_num < 0.92 * RAND_MAX)
			count_left_leaf(&k);
		else if (rand_num < 0.99 * RAND_MAX)
			count_right_leaf(&k);
		else
		{
			k.x = 0;
			k.y = 0.16 * k.y;
			k.c = 0;
		}
		count_color_leaf(fractal, k);
	}
}
