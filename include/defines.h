/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 19:53:30 by hdean             #+#    #+#             */
/*   Updated: 2020/03/15 23:08:19 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define THREADS 8

/*
** FRACTALS
*/
# define JULIA 1
# define MANDELBROT 2
# define FROSTY 3
# define RADIOLARIA 4
# define SPIDER 5
# define BURNING_SHIP 6
# define NEWTON 7
# define NOVA 8
# define LEAF 9
# define PITER 10
# define CLIFFORD 11

# define MAX_ITER 100
# define MAX_ITER_DOT 100000
# define MAX_COLOR_SCHEME 10
# define FRACTALLS_AT_ALL 11
# define HEIGHT 1000
# define WIDTH 1000

/*
** ERRORS
*/
# define MLX_ERROR 1
# define USAGE 2
# define FRACTAL_TYPE 3
# define WINDOW_SIZE 4
# define MALLOC 5
# define CL_ERROR 6
# define CL_READ_ERROR 7
# define ERR_TREADS 8

/*
** KEYS DEFINE
*/
# define MOUSE_LEFT 1
# define MOUSE_DOWN 4
# define MOUSE_UP 5
# define LEFT 123
# define RIGHT 124
# define UP 125
# define DOWN 126
# define COLOR 8

# define COLOR_NUM 82
# define RAINBOW_SCHEME 83
# define BAW_SCHEME 84
# define FYTI_SCHEME 85
# define GRAY_SCHEME 86
# define DB_SCHEME 87
# define DR_SCHEME 88
# define SEA_SCHEME 89
# define BLUE_SCHEME 91
# define RANDOM_SCHEME 92

# define MAX_ITERATION_MINUS 43
# define MAX_ITERATION_PLUS 47
# define STOP_OR_RUN_JULIA 38
# define ESC 53
# define RESET 49
# define GPU_ON_OFF 5
# define ZOOM_PLUS 24
# define ZOOM_PLUS_NUM 69
# define ZOOM_MINUS_NUM 78
# define ZOOM_MINUS 27
# define SWITCH_FRACTAL 3
# define JULIA_KEY 18
# define MANDELBROT_KEY 19
# define FROSTY_KEY 20
# define RADIOLARIA_KEY 21
# define SPIDER_KEY 23
# define SHIP_KEY 22
# define NEWTON_KEY 26
# define NOVA_KEY 28
# define LEAF_KEY 12
# define PITER_KEY 13
# define CLIFFORD_KEY 14

/*
**COLORS
*/
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define LIME 0x00FF00
# define PINK 0xFF1493
# define RED 0xFF4500
# define CSEA 0x20B2AA
# define YELLOW 0xFEE08B
# define GREEN	0x22FF76
# define FOREST_GREEN 0x228B22
# define DARK_GREEN 0x556B2F

/*
** COLOR SCHEMES
*/
# define RAINBOW_COLOR 0
# define BLACK_AND_WHITE 1
# define FROM_YELLOW_TO_INF 2
# define GRAY_SCALE 3
# define DARK_BLUE 4
# define DARK_RED 5
# define SEA 6
# define BLUE 7
# define RANDOM 8
# define RAD_SP 9

#endif
