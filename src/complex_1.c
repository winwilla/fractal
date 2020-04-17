/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 22:30:14 by hdean             #+#    #+#             */
/*   Updated: 2020/03/15 00:00:31 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"
#include <math.h>

t_complex	complex_sin(t_complex c)
{
	t_complex res;

	res.re = sin(c.re) * cosh(c.im);
	res.im = cos(c.re) * sinh(c.im);
	return (res);
}

t_complex	complex_cos(t_complex c)
{
	t_complex res;

	res.re = cos(c.re) * cosh(c.im);
	res.im = -sin(c.re) * sinh(c.im);
	return (res);
}

t_complex	complex_div(t_complex a, t_complex b)
{
	t_complex res;

	res.re = (a.re * b.re + a.im * b.im) / complex_abs(b);
	res.im = (a.im * b.re - a.re * b.im) / complex_abs(b);
	return (res);
}

t_complex	func(t_complex z, int d)
{
	t_complex tmp;

	if (d)
	{
		tmp.re = 3 * (z.re * z.re - z.im * z.im);
		tmp.im = 6 * z.re * z.im;
	}
	else
	{
		tmp.re = z.re * z.re * z.re - 3 * z.re * z.im * z.im - 1;
		tmp.im = 3 * z.re * z.re * z.im - z.im * z.im * z.im;
	}
	return (tmp);
}

t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex res;

	res.re = a.re + b.re;
	res.im = a.im + b.im;
	return (res);
}
