/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_cl.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:20:39 by hdean             #+#    #+#             */
/*   Updated: 2020/03/15 22:01:08 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_CL_H
# define FRACTOL_CL_H

# define WIDTH 1000
# define HEIGHT 1000

# define JULIA_CL 1
# define MANDELBROT_CL 2
# define FROSTY_CL 3
# define RADIOLARIA_CL 4
# define SPIDER_CL 5
# define BURNING_SHIP_CL 6
# define NEWTON_CL 7
# define NOVA_CL 8

# define RAINBOW_COLOR_CL 0
# define BLACK_AND_WHITE_CL 1
# define FROM_YELLOW_CL 2
# define GRAY_SCALE_CL 3
# define DARK_BLUE_CL 4
# define DARK_RED_CL 5
# define SEA_CL 6
# define BLUE_CL 7
# define RANDOM_CL 8
# define RAD_SP_CL 9

typedef struct			s_complex_cl
{
	double				re;
	double				im;
}						t_complex_cl;

typedef struct			s_color_params_cl
{
	double				f_red;
	double				f_green;
	double				f_blue;
	double				p_red;
	double				p_green;
	double				p_blue;
	int					width;
	int					center;
}						t_color_params_cl;

typedef	struct			s_fractal_cl
{
	int					type;
	int					max_iter;
	t_complex_cl		min;
	t_complex_cl		max;
	t_complex_cl		k;
	t_complex_cl		d;
	int					color;
	t_color_params_cl	r;
}						t_fractal_cl;

#endif
