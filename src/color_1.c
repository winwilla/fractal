/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 15:51:46 by hdean             #+#    #+#             */
/*   Updated: 2020/03/15 01:52:42 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	dark_red(int iteration, int max_iteration)
{
	t_color color;

	color.blue = 0;
	color.green = 0;
	color.red = 0;
	if (iteration < max_iteration)
		color.red = (iteration * 6) % 255;
	return (color);
}

t_color	sea_color(int i, int i_max)
{
	t_color color;

	color.red = 0;
	color.green = 0;
	color.blue = 0;
	if (i < i_max)
	{
		color.green = (30 * i) % 255;
		color.blue = (30 * i) % 255;
	}
	return (color);
}

t_color	gray_scale(int iteration, int max_iteration)
{
	t_color	color;

	if (iteration == max_iteration)
		return (convert_color_int_to_rgb(BLACK));
	color.red = sin(0.3 * (double)iteration) * 127 + 128;
	color.green = sin(0.3 * (double)iteration) * 127 + 128;
	color.blue = sin(0.3 * (double)iteration) * 127 + 128;
	return (color);
}

t_color	dark_blue(int iteration, int max_iteration)
{
	double		t;
	t_color		color;

	t = (double)iteration / (double)max_iteration;
	color.red = (int)(9 * (1 - t) * pow(t, 3) * 255);
	color.green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
	return (color);
}
