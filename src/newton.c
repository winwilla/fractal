/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 23:11:54 by hdean             #+#    #+#             */
/*   Updated: 2020/03/15 04:06:44 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_z(t_params *p, t_fractal *fractal)
{
	t_complex	root1;
	t_complex	root2;
	t_complex	root3;
	double		res;
	double		tmp;

	root1 = new_complex(1.0, 0.0);
	root2 = new_complex(-0.5, 0.86602540378);
	root3 = new_complex(-0.5, -0.86602540378);
	res = sqrt(complex_abs_min(p->z, root1));
	tmp = sqrt(complex_abs_min(p->z, root2));
	res = tmp > res ? res : tmp;
	tmp = sqrt(complex_abs_min(p->z, root3));
	res = tmp > res ? res : tmp;
	if (res < 0.000001)
	{
		draw_pixel(p->x, p->y, choose_color_scheme(p->i,
										fractal, p->z), fractal);
		return (1);
	}
	return (0);
}

void		draw_newton(t_fractal *fractal)
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
			while (++p.i < fractal->max_iter)
			{
				p.t = complex_div(func(p.z, 0), func(p.z, 1));
				p.z = complex_add(p.z, new_complex(-p.t.re, -p.t.im));
				if (check_z(&p, fractal))
					break ;
			}
			p.x++;
		}
		p.y++;
	}
}
