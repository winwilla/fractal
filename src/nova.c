/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nova.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:02:11 by hdean             #+#    #+#             */
/*   Updated: 2020/03/15 04:06:55 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	count_new_z(t_params *p)
{
	t_complex	old_z;

	old_z = p->z;
	p->t = complex_div(func(p->z, 0), func(p->z, 1));
	p->t = new_complex(-p->t.re, -p->t.im);
	p->z = complex_add(p->z, p->t);
	p->z = complex_add(p->z, p->c);
	return (sqrt(complex_abs_min(p->z, old_z)) < 0.0005);
}

void		draw_nova(t_fractal *fractal)
{
	t_params	p;

	p.y = fractal->start_line;
	while (p.y < fractal->end_line)
	{
		p.x = 0;
		while (p.x < fractal->image.width)
		{
			p.c.im = fractal->min.re + p.x * fractal->d.re;
			p.c.re = -fractal->max.im + p.y * fractal->d.im;
			p.z = new_complex(1.0, 0.0);
			p.i = -1;
			while (++p.i < fractal->max_iter)
			{
				if (count_new_z(&p))
					break ;
			}
			draw_pixel(p.x, p.y, choose_color_scheme(p.i,
										fractal, p.z), fractal);
			p.x++;
		}
		p.y++;
	}
}
