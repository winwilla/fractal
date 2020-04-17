/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 21:06:00 by hdean             #+#    #+#             */
/*   Updated: 2020/03/15 04:06:36 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot(t_fractal *fractal)
{
	t_params	p;

	p.y = fractal->start_line;
	while (p.y < fractal->end_line)
	{
		p.c.im = fractal->max.im - p.y * fractal->d.im;
		p.x = 0;
		while (p.x < fractal->image.width)
		{
			p.c.re = fractal->min.re + p.x * fractal->d.re;
			p.z = new_complex(p.c.re, p.c.im);
			p.i = -1;
			while (++p.i < fractal->max_iter && sqrt(complex_abs(p.z)) <= 4)
				p.z = complex_add(complex_mult(p.z, p.z), p.c);
			draw_pixel(p.x, p.y, choose_color_scheme(p.i,
										fractal, p.z), fractal);
			p.x++;
		}
		p.y++;
	}
}
