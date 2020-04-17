/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 23:48:05 by hdean             #+#    #+#             */
/*   Updated: 2020/03/15 03:55:13 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** KEY PRESS HOOKS
*/

static int	key_press_helper(int key, t_fractal *fractal)
{
	if (key == ESC)
		close_hook(fractal);
	if (key == RESET)
		reset_fractal(fractal);
	if (key == GPU_ON_OFF)
		fractal->gpu = (fractal->gpu) ? 0 : 1;
	if (key == LEFT || key == RIGHT || key == UP || key == DOWN)
		move_hook(key, fractal);
	return (0);
}

int			key_press(int key, void *param)
{
	key_press_helper(key, (t_fractal *)param);
	if (key == COLOR || key == COLOR_NUM || key == BAW_SCHEME ||
		key == GRAY_SCHEME || key == DB_SCHEME || key == DR_SCHEME ||
		key == SEA_SCHEME || key == BLUE_SCHEME || key == RANDOM_SCHEME ||
		key == RAINBOW_SCHEME || key == FYTI_SCHEME)
		change_color_scheme(key, (t_fractal *)param);
	if (key == MAX_ITERATION_MINUS || key == MAX_ITERATION_PLUS)
		change_max_iteration(key, (t_fractal *)param);
	if (key == STOP_OR_RUN_JULIA)
		((t_fractal *)param)->julia_motion =
								(((t_fractal *)param)->julia_motion) ? 0 : 1;
	if (key == ZOOM_PLUS || key == ZOOM_MINUS ||
		key == ZOOM_PLUS_NUM || key == ZOOM_MINUS_NUM)
		scale_window(key, (t_fractal *)param);
	if (key == SWITCH_FRACTAL || key == JULIA_KEY || key == MANDELBROT_KEY ||
		key == FROSTY_KEY || key == RADIOLARIA_KEY || key == SPIDER_KEY ||
		key == SHIP_KEY || key == NEWTON_KEY || key == LEAF_KEY ||
		key == NOVA_KEY || key == PITER_KEY || key == CLIFFORD_KEY)
		draw_next_fractal(key, (t_fractal *)param);
	draw_fractal((t_fractal *)param);
	return (0);
}

/*
** COLOR SCHEME
*/

int			change_color_scheme(int key, t_fractal *fractal)
{
	if (key == COLOR || key == COLOR_NUM)
		switch_color_scheme(fractal);
	if (key == RAINBOW_SCHEME)
		fractal->color = RAINBOW_COLOR;
	else if (key == BAW_SCHEME)
		fractal->color = BLACK_AND_WHITE;
	else if (key == FYTI_SCHEME)
		fractal->color = FROM_YELLOW_TO_INF;
	else if (key == GRAY_SCHEME)
		fractal->color = GRAY_SCALE;
	else if (key == DB_SCHEME)
		fractal->color = DARK_BLUE;
	else if (key == DR_SCHEME)
		fractal->color = DARK_RED;
	else if (key == SEA_SCHEME)
		fractal->color = SEA;
	else if (key == BLUE_SCHEME)
		fractal->color = BLUE;
	else if (key == RANDOM_SCHEME)
	{
		init_random_color(fractal);
		fractal->color = RANDOM;
	}
	return (0);
}

/*
** DRAW NEXT FRACTAL
*/

static void	next_fractals(int key, t_fractal *fractal)
{
	if (key == SHIP_KEY)
		fractal->type = BURNING_SHIP;
	else if (key == NEWTON_KEY)
		fractal->type = NEWTON;
	else if (key == LEAF_KEY)
		fractal->type = LEAF;
	else if (key == NOVA_KEY)
		fractal->type = NOVA;
	else if (key == PITER_KEY)
		fractal->type = PITER;
	else if (key == CLIFFORD_KEY)
		fractal->type = CLIFFORD;
}

int			draw_next_fractal(int key, t_fractal *fractal)
{
	if (key == SWITCH_FRACTAL)
	{
		fractal->type += 1;
		if (fractal->type > FRACTALLS_AT_ALL)
			fractal->type = JULIA;
	}
	else if (key == JULIA_KEY)
		fractal->type = JULIA;
	else if (key == MANDELBROT_KEY)
		fractal->type = MANDELBROT;
	else if (key == FROSTY_KEY)
		fractal->type = FROSTY;
	else if (key == RADIOLARIA_KEY)
		fractal->type = RADIOLARIA;
	else if (key == SPIDER_KEY)
		fractal->type = SPIDER;
	else
		next_fractals(key, fractal);
	set_init_params(fractal);
	return (0);
}
