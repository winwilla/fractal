/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 15:52:27 by hdean             #+#    #+#             */
/*   Updated: 2020/03/15 04:03:36 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			draw_pixel(int x, int y, t_color color, t_fractal *fractal)
{
	int i;

	i = (x * fractal->image.bits_per_pixel / 8) +
		(y * fractal->image.line_size);
	fractal->image.data[i] = color.blue;
	fractal->image.data[++i] = color.green;
	fractal->image.data[++i] = color.red;
	return (0);
}

t_color		smooth_color(t_color_params c, int i, double abs_z, double p)
{
	t_color	color;
	double	t;

	t = i + 10 - log2(log2(abs_z)) / log2(p);
	color.red = (int)(sin(c.f_red * t + c.p_red) * c.width + c.center);
	color.green = (int)(sin(c.f_green * t + c.p_green) * c.width + c.center);
	color.blue = (int)(sin(c.f_blue * t + c.p_blue) * c.width + c.center);
	return (color);
}

t_color		rad_sp_scheme(t_complex z)
{
	if (fabs(z.re) >= 300 || fabs(z.im) >= 10000)
		return (convert_color_int_to_rgb(0xFFD700));
	return (convert_color_int_to_rgb(BLACK));
}

t_color		choose_color_scheme(int i, t_fractal *fractal, t_complex z)
{
	double abs_z;

	abs_z = complex_abs(z);
	if (fractal->color == RAINBOW_COLOR)
		return (rainbow_scheme(i, fractal->max_iter, sqrt(abs_z)));
	else if (fractal->color == BLACK_AND_WHITE)
		return (black_and_white_scheme(i, fractal->max_iter, sqrt(abs_z)));
	else if (fractal->color == FROM_YELLOW_TO_INF)
		return (from_yellow_to_inf_scheme(i, fractal->max_iter, sqrt(abs_z)));
	else if (fractal->color == GRAY_SCALE)
		return (gray_scale(i, fractal->max_iter));
	else if (fractal->color == DARK_BLUE)
		return (dark_blue(i, fractal->max_iter));
	else if (fractal->color == DARK_RED)
		return (dark_red(i, fractal->max_iter));
	else if (fractal->color == SEA)
		return (sea_color(i, fractal->max_iter));
	else if (fractal->color == BLUE)
		return (blue_scheme(i, fractal->max_iter, sqrt(abs_z)));
	else if (fractal->color == RANDOM)
		return (random_scheme(i, fractal->max_iter, sqrt(abs_z),
															fractal->random));
	else if (fractal->color == RAD_SP && fractal->type == RADIOLARIA)
		return (rad_sp_scheme(z));
	return (convert_color_int_to_rgb(WHITE));
}
