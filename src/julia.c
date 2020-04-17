/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:53:03 by hdean             #+#    #+#             */
/*   Updated: 2020/03/15 04:06:29 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_fractal *fractal)
{
	t_complex	z;
	int			x;
	int			y;
	int			i;

	y = fractal->start_line;
	while (y < fractal->end_line)
	{
		x = 0;
		while (x < fractal->image.width)
		{
			z.re = fractal->min.re + x * fractal->d.re;
			z.im = fractal->max.im - y * fractal->d.im;
			i = -1;
			while (++i < fractal->max_iter && sqrt(complex_abs(z)) <= 4)
				z = complex_add(complex_mult(z, z), fractal->k);
			draw_pixel(x, y, choose_color_scheme(i, fractal, z), fractal);
			x++;
		}
		y++;
	}
}

void	draw_frosty(t_fractal *fractal)
{
	t_params	p;

	p.y = fractal->start_line;
	while (p.y < fractal->end_line)
	{
		p.x = 0;
		while (p.x < fractal->image.width)
		{
			p.z.re = fractal->min.re + p.x * fractal->d.re;
			p.z.im = fractal->max.im - p.y * fractal->d.im;
			p.i = -1;
			while (++p.i < fractal->max_iter && sqrt(complex_abs(p.z)) <= 100)
			{
				p.t = p.z;
				p.z = complex_add(
					complex_sin(complex_add(p.t, new_complex(0.3, 0.4))),
					complex_cos(complex_add(p.t, new_complex(-0.03, 0.04))));
			}
			draw_pixel(p.x, p.y, choose_color_scheme(p.i, fractal,
					p.z), fractal);
			p.x++;
		}
		p.y++;
	}
}
