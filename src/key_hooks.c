/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 21:55:38 by hdean             #+#    #+#             */
/*   Updated: 2020/03/15 22:22:40 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** MOVE
*/

int			move_hook(int key, t_fractal *fractal)
{
	if (key == RIGHT)
	{
		fractal->min.re -= fractal->d.re * 10.0;
		fractal->max.re -= fractal->d.re * 10.0;
		fractal->start_point_leaf.x += 10.0;
	}
	else if (key == LEFT)
	{
		fractal->min.re += fractal->d.re * 10.0;
		fractal->max.re += fractal->d.re * 10.0;
		fractal->start_point_leaf.x -= 10.0;
	}
	if (key == DOWN)
	{
		fractal->min.im -= fractal->d.im * 10.0;
		fractal->max.im -= fractal->d.im * 10.0;
		fractal->start_point_leaf.y -= 10.0;
	}
	else if (key == UP)
	{
		fractal->min.im += fractal->d.im * 10.0;
		fractal->max.im += fractal->d.im * 10.0;
		fractal->start_point_leaf.y += 10.0;
	}
	return (0);
}

/*
** MAX_ITERATION
*/

static void	change_max_iteration_iter(int key, t_fractal *fractal)
{
	if (key == MAX_ITERATION_PLUS)
	{
		if (fractal->max_iter < 100)
			fractal->max_iter += 10;
		else if (fractal->max_iter < 10000)
			fractal->max_iter = (int)(fractal->max_iter * 1.2);
		else if (fractal->max_iter >= 10000 && fractal->max_iter <= 990000)
			fractal->max_iter += 10000;
	}
	if (key == MAX_ITERATION_MINUS)
	{
		if (fractal->max_iter > 11 && fractal->max_iter < 100)
			fractal->max_iter -= 10;
		else if (fractal->max_iter >= 100 && fractal->max_iter < 10000)
			fractal->max_iter = (int)(fractal->max_iter * 0.8);
		else if (fractal->max_iter >= 10000)
			fractal->max_iter -= 10000;
	}
}

int			change_max_iteration(int key, t_fractal *fractal)
{
	if (fractal->type == LEAF || fractal->type == PITER ||
											fractal->type == CLIFFORD)
		change_max_iteration_iter(key, fractal);
	else
	{
		if (key == MAX_ITERATION_PLUS)
		{
			if (fractal->max_iter < 10)
				fractal->max_iter += 1;
			if (fractal->max_iter < 200)
				fractal->max_iter = (int)(fractal->max_iter * 1.2);
			else if (fractal->max_iter < 5000)
				fractal->max_iter += 100;
		}
		if (key == MAX_ITERATION_MINUS)
		{
			if (fractal->max_iter > 3 && fractal->max_iter < 10)
				fractal->max_iter = fractal->max_iter - 1;
			else if (fractal->max_iter >= 10 && fractal->max_iter < 500)
				fractal->max_iter = (int)(fractal->max_iter * 0.8);
			else if (fractal->max_iter >= 500)
				fractal->max_iter = fractal->max_iter - 100;
		}
	}
	return (0);
}

/*
** ZOOM
*/

int			scale_window(int key, t_fractal *fractal)
{
	double		k;
	t_complex	delta;

	k = (key == ZOOM_PLUS || key == ZOOM_PLUS_NUM) ? 0.8 : 1.2;
	if ((key == ZOOM_PLUS || key == ZOOM_PLUS_NUM) && (fractal->zoom < 1000))
		fractal->zoom += 0.2;
	else if ((key == ZOOM_MINUS || key == ZOOM_MINUS_NUM) &&
													(fractal->zoom > 0.2))
		fractal->zoom -= 0.2;
	delta.re = -(fractal->max.re + fractal->min.re) / 2;
	delta.im = -(fractal->max.im + fractal->min.im) / 2;
	fractal->min = complex_add(fractal->min, delta);
	fractal->max = complex_add(fractal->max, delta);
	fractal->min = complex_mult_num(fractal->min, k);
	fractal->max = complex_mult_num(fractal->max, k);
	fractal->d = new_complex(
		(fractal->max.re - fractal->min.re) / fractal->image.width,
		(fractal->max.im - fractal->min.im) / fractal->image.height);
	delta.re = -delta.re;
	delta.im = -delta.im;
	fractal->min = complex_add(fractal->min, delta);
	fractal->max = complex_add(fractal->max, delta);
	return (0);
}

/*
** CLOSE
*/

int			close_hook(void *param)
{
	terminate_all(0, (t_fractal *)param);
	exit(0);
}
