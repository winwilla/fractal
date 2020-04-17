/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spider.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 22:47:27 by hdean             #+#    #+#             */
/*   Updated: 2020/03/15 04:07:02 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_spider(t_fractal *fractal)
{
	t_params	p;

	p.y = fractal->start_line;
	while (p.y < fractal->end_line)
	{
		p.x = 0;
		while (p.x < fractal->image.width)
		{
			p.z = new_complex(fractal->min.re + p.x * fractal->d.re,
							fractal->max.im - p.y * fractal->d.im);
			p.c = p.z;
			p.i = -1;
			while (++p.i < fractal->max_iter && sqrt(complex_abs(p.z)) <= 4)
			{
				p.t = complex_mult(p.z, p.z);
				p.z = complex_add(p.t, p.c);
				p.c.re = p.c.re / 2 + p.z.re;
				p.c.im = p.c.im / 2 + p.z.im;
			}
			draw_pixel(p.x, p.y, choose_color_scheme(p.i,
										fractal, p.z), fractal);
			p.x++;
		}
		p.y++;
	}
}
