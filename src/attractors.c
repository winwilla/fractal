/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attractors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:44:04 by hdean             #+#    #+#             */
/*   Updated: 2020/03/13 17:23:16 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		init_params_iter(t_coord *i, t_coord *j, int type)
{
	if (type == PITER)
	{
		i->x = 2.7;
		i->y = -0.9;
		j->x = -0.86;
		j->y = -2.2;
	}
	else if (type == CLIFFORD)
	{
		i->x = 1.5;
		i->y = -1.8;
		j->x = 1.6;
		j->y = 0.9;
	}
}

static	void	draw_point(t_coord p, t_fractal *fractal)
{
	int x;
	int y;
	int i;
	int color;

	color = (fractal->type == PITER) ? PINK : GREEN;
	x = round(p.x * 150 * fractal->zoom + fractal->start_point_leaf.x);
	y = round(p.y * 150 * fractal->zoom + fractal->start_point_leaf.y);
	if (x > 0 && x < 1000 && y > 0 && y < 1000)
	{
		i = (x * fractal->image.bits_per_pixel / 8) +
			(y * fractal->image.line_size);
		if (fractal->image.data[i] == 0 && fractal->image.data[i + 1] == 0 &&
					fractal->image.data[i + 2] == 0)
			draw_pixel(x, y, convert_color_int_to_rgb(color), fractal);
		else
		{
			fractal->image.data[i] = (fractal->image.data[i] + 5) % 256;
			fractal->image.data[i + 1] = (fractal->image.data[i + 1] + 5) % 256;
			fractal->image.data[i + 2] = (fractal->image.data[i + 2] + 5) % 256;
		}
	}
}

void			draw_piter(t_fractal *fractal)
{
	t_coord i;
	t_coord j;
	t_coord p;
	t_coord tp;

	p.c = 0;
	p.x = 0.0;
	p.y = 0.0;
	init_params_iter(&i, &j, fractal->type);
	while (++p.c < fractal->max_iter)
	{
		tp.x = p.x;
		tp.y = p.y;
		p.x = sin(i.x * tp.y) - cos(i.y * tp.x);
		p.y = sin(j.y * tp.x) - cos(j.y * tp.y);
		draw_point(p, fractal);
	}
}

void			draw_klifford(t_fractal *fractal)
{
	t_coord i;
	t_coord j;
	t_coord p;
	t_coord tp;

	p.c = 0;
	p.x = 0.0;
	p.y = 0.0;
	init_params_iter(&i, &j, fractal->type);
	while (++p.c < fractal->max_iter)
	{
		tp.x = p.x;
		tp.y = p.y;
		p.x = sin(i.x * tp.y) + j.x * cos(i.x * tp.x);
		p.y = sin(i.y * tp.x) + j.y * cos(i.y * tp.y);
		draw_point(p, fractal);
	}
}
