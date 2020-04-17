/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 22:14:28 by hdean             #+#    #+#             */
/*   Updated: 2020/03/14 17:43:24 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	other_fractals2(t_fractal *fractal, int x, int y)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = fractal->image.mlx_ptr;
	win_ptr = fractal->image.win_ptr;
	if (fractal->type == NOVA)
		mlx_string_put(mlx_ptr, win_ptr, x, y + 550, PINK, "8 - Nova");
	else
		mlx_string_put(mlx_ptr, win_ptr, x, y + 550, CSEA, "8 - Nova");
	if (fractal->type == LEAF)
		mlx_string_put(mlx_ptr, win_ptr, x, y + 580, PINK, "Q - Fern leaf");
	else
		mlx_string_put(mlx_ptr, win_ptr, x, y + 580, CSEA, "Q - Fern leaf");
	if (fractal->type == PITER)
		mlx_string_put(mlx_ptr, win_ptr, x, y + 610, PINK,
												"W - Peter de Jong Attractor");
	else
		mlx_string_put(mlx_ptr, win_ptr, x, y + 610, CSEA,
												"W - Peter de Jong Attractor");
	if (fractal->type == CLIFFORD)
		mlx_string_put(mlx_ptr, win_ptr, x, y + 640, PINK,
													"E - Clifford Attractor");
	else
		mlx_string_put(mlx_ptr, win_ptr, x, y + 640, CSEA,
													"E - Clifford Attractor");
}

static void	other_fractals(t_fractal *fractal, int x, int y)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = fractal->image.mlx_ptr;
	win_ptr = fractal->image.win_ptr;
	if (fractal->type == SPIDER)
		mlx_string_put(mlx_ptr, win_ptr, x, y + 460, PINK, "5 - Spider");
	else
		mlx_string_put(mlx_ptr, win_ptr, x, y + 460, CSEA, "5 - Spider");
	if (fractal->type == BURNING_SHIP)
		mlx_string_put(mlx_ptr, win_ptr, x, y + 490, PINK, "6 - Burning ship");
	else
		mlx_string_put(mlx_ptr, win_ptr, x, y + 490, CSEA, "6 - Burning ship");
	if (fractal->type == NEWTON)
		mlx_string_put(mlx_ptr, win_ptr, x, y + 520, PINK, "7 - Newton");
	else
		mlx_string_put(mlx_ptr, win_ptr, x, y + 520, CSEA, "7 - Newton");
	other_fractals2(fractal, x, y);
	mlx_string_put(mlx_ptr, win_ptr, x, y + 690, CSEA, "Iterations: ");
	put_params(fractal, x, y + 140);
}

static void	put_list_of_fractals(t_fractal *fractal, int x, int y)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = fractal->image.mlx_ptr;
	win_ptr = fractal->image.win_ptr;
	mlx_string_put(mlx_ptr, win_ptr, x, y + 340, CSEA, "LIST OF FRACTALS");
	if (fractal->type == JULIA)
		mlx_string_put(mlx_ptr, win_ptr, x, y + 380, PINK, "1 - Julia");
	else
		mlx_string_put(mlx_ptr, win_ptr, x, y + 380, CSEA, "1 - Julia");
	if (fractal->type == MANDELBROT)
		mlx_string_put(mlx_ptr, win_ptr, x, y + 410, PINK, "2 - Mandelbrot");
	else
		mlx_string_put(mlx_ptr, win_ptr, x, y + 410, CSEA, "2 - Mandelbrot");
	if (fractal->type == FROSTY)
		mlx_string_put(mlx_ptr, win_ptr, x, y + 440, PINK, "3 - Frosty");
	else
		mlx_string_put(mlx_ptr, win_ptr, x, y + 440, CSEA, "3 - Frosty");
	if (fractal->type == RADIOLARIA)
		mlx_string_put(mlx_ptr, win_ptr, x, y + 470, PINK, "4 - Radiolaria");
	else
		mlx_string_put(mlx_ptr, win_ptr, x, y + 470, CSEA, "4 - Radiolaria");
	other_fractals(fractal, x, y + 40);
}

static void	continue_with_menu(t_fractal *fractal, int x, int y)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = fractal->image.mlx_ptr;
	win_ptr = fractal->image.win_ptr;
	mlx_string_put(mlx_ptr, win_ptr, x, y + 190, CSEA, "Iterations:");
	mlx_string_put(mlx_ptr, win_ptr, x + 160, y + 190, YELLOW, "[<][>]");
	mlx_string_put(mlx_ptr, win_ptr, x, y + 220, CSEA, "Mouse mode for Julia:");
	mlx_string_put(mlx_ptr, win_ptr, x + 220, y + 220, YELLOW, "[J]");
	mlx_string_put(mlx_ptr, win_ptr, x, y + 250, CSEA, "GPU mode:");
	mlx_string_put(mlx_ptr, win_ptr, x + 160, y + 250, YELLOW, "[G]");
	mlx_string_put(mlx_ptr, win_ptr, x, y + 280, CSEA, "Reset:");
	mlx_string_put(mlx_ptr, win_ptr, x + 160, y + 280, YELLOW, "[space]");
	mlx_string_put(mlx_ptr, win_ptr, x, y + 310, CSEA, "Exit:");
	mlx_string_put(mlx_ptr, win_ptr, x + 160, y + 310, YELLOW, "[esc]");
	put_list_of_fractals(fractal, x, y + 40);
}

void		put_menu_to_window(t_fractal *fractal)
{
	int		x;
	int		y;
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = fractal->image.mlx_ptr;
	win_ptr = fractal->image.win_ptr;
	x = 1010;
	y = 50;
	mlx_string_put(mlx_ptr, win_ptr, x, y, CSEA, "CONTROLS");
	mlx_string_put(mlx_ptr, win_ptr, x, y + 40, CSEA, "Choose fractal:");
	mlx_string_put(mlx_ptr, win_ptr, x + 160, y + 40, YELLOW,
															"[F] or [1 .. 8]");
	mlx_string_put(mlx_ptr, win_ptr, x + 160, y + 70, YELLOW, "[Q][W][E]");
	mlx_string_put(mlx_ptr, win_ptr, x, y + 100, CSEA, "Color scheme:");
	mlx_string_put(mlx_ptr, win_ptr, x + 160, y + 100, YELLOW,
													"[C] or [num 0 .. 9]");
	mlx_string_put(mlx_ptr, win_ptr, x, y + 130, CSEA, "Translation:");
	mlx_string_put(mlx_ptr, win_ptr, x + 160, y + 130, YELLOW, "[arrows]");
	mlx_string_put(mlx_ptr, win_ptr, x, y + 160, CSEA, "Zooming:");
	mlx_string_put(mlx_ptr, win_ptr, x + 160, y + 160, YELLOW,
													"[+/-][num +/-]");
	mlx_string_put(mlx_ptr, win_ptr, x + 160, y + 190, YELLOW, "[mouse wheel]");
	continue_with_menu(fractal, x, y + 30);
}
