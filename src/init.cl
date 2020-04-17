#include "fractol_cl.h"

t_complex_cl new_complex_cl(double a, double b)
{
	t_complex_cl new;

	new.re = a;
	new.im = b;
	return (new);
}

double complex_abs_cl(t_complex_cl c)
{
	double res;

	res = c.re * c.re + c.im * c.im;
	return (res);
}

t_complex_cl complex_mult_cl(t_complex_cl a, t_complex_cl b)
{
	t_complex_cl res;

	res.re = a.re * b.re - b.im * b.im;
	res.im = a.re * b.im + b.im * a.re;
	return (res); 
}

t_complex_cl complex_add_cl(t_complex_cl a, t_complex_cl b)
{
	t_complex_cl res;

	res.re = a.re + b.re;
	res.im = a.im + b.im;
	return (res);
}

t_complex_cl complex_sin_cl(t_complex_cl c)
{
	t_complex_cl res;

	res.re = sin(c.re) * cosh(c.im);
	res.im = cos(c.re) * sinh(c.im);
	return (res);
}

t_complex_cl complex_cos_cl(t_complex_cl c)
{
	t_complex_cl res;

	res.re = cos(c.re) * cosh(c.im);
	res.im = -sin(c.re) * sinh(c.im);
	return (res);
}

t_complex_cl complex_div_cl(t_complex_cl a, t_complex_cl b)
{
	t_complex_cl res;

	res.re = (a.re * b.re + a.im * b.im) / complex_abs_cl(b);
	res.im = (a.im * b.re - a.re * b.im) / complex_abs_cl(b);
	return (res);
}

t_complex_cl	func_cl(t_complex_cl z, int d)
{
	t_complex_cl tmp;

	if (d == 1)
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

int	dark_red(int i, int i_max)
{
	int red = 0;
	int green = 0;
	int blue = 0;

	if (i < i_max)
		red = (i * 6) % 255;
	return ((red << 16) + (green << 8) + blue);
}

int sea_color(int i, int i_max)
{
	int red = 0;
	int green = 0;
	int blue = 0;

	if (i < i_max)
	{
		green = (30 * i) % 255;
		blue = (30 * i) % 255;
	}
	return ((red << 16) + (green << 8) + blue);
}

int dark_blue(int iteration, int max_iteration)
{
	double t;
	int red;
	int green;
	int blue;

	t = (double)iteration / (double)max_iteration;
	red = 9 * (1 - t) * pow(t, 3) * 255;
	green = 15 * pow((1 - t), 2) * pow(t, 2) * 255;
	blue = 8.5 * pow((1 - t), 3) * t * 255;
	return ((red << 16) + (green << 8) + blue);
}

int	gray_scale(int iteration, int max_iteration)
{
	int red;
	int green;
	int blue;
	
	if (iteration == max_iteration)
		return (0);
	red = sin(0.3 * (double)iteration) * 127 + 128;
	green = sin(0.3 * (double)iteration) * 127 + 128;
	blue = sin(0.3 * (double)iteration) * 127 + 128;
	return ((red << 16) + (green << 8) + blue);
}

int	rainbow_scheme(int i, int i_max, double abs_z)
{
	if (i == i_max)
		return (0);
	double t = i + 10 - log2(log2(abs_z));
	int red = (int)(sin(0.4 * t + 2) * 127 + 128);
	int green = (int)(sin(0.3 * t + 2 * M_PI_2) * 127 + 128);
	int blue = (int)(sin(0.1 * t + 2 * M_PI_4) * 127 + 128);
	return ((red << 16) + (green << 8) + blue);
}

int	black_and_white_scheme(int i, int i_max, double abs_z)
{
	if (i == i_max)
		return (0);
	double t = i + 10 - log2(log2((abs_z)));
	int red = (int)(sin(0.33 * t) * 128 + 127);
	int green = (int)(sin(0.33 * t) * 128 + 127);
	int blue = (int)(sin(0.33 * t) * 128 + 127);
	return ((red << 16) + (green << 8) + blue);
}

int from_yellow_to_white(int i, int i_max, double abs_z)
{
	if (i == i_max)
		return (0);
	double t = i + 10 - log2(log2((abs_z)));
	int red = (int)(sin(0.1 * t) * 128 + 127);
	int green = (int)(sin(0.2 * t) * 128 + 127);
	int blue = (int)(sin(0.3 * t) * 128 + 127);
	return ((red << 16) + (green << 8) + blue);
}

int	blue_scheme(int i, int i_max, double abs_z)
{
	if (i == i_max)
		return (0);
	double t = i + 10 - log2(log2((abs_z)));
	int red = (int)(sin(1.1 * t) * 127 + 128);
	int green = (int)(sin(5.2 * t + 2) * 127 + 128);
	int blue = (int)(sin(3.3 * t + 4) * 127 + 128);
	return ((red << 16) + (green << 8) + blue);
}

int	random_scheme(int i, int i_max, double abs_z, t_color_params_cl p)
{
	if (i == i_max)
		return (0);
	double t = i + 10 - log2(log2((abs_z)));
	int red = (int)(sin(p.f_red * t + p.p_red) * p.width + p.center);
	int green = (int)(sin(p.f_green * t + p.p_green) * p.width + p.center);
	int blue = (int)(sin(p.f_blue * t + p.p_blue) * p.center + p.width);
	return ((red << 16) + (green << 8) + blue);
}

__kernel void fractals(
			__global int *out, t_fractal_cl var)
{
	int				i;
	int				j;

	int				iter;
	int				col;

	t_complex_cl	z;
	t_complex_cl	old_z;
	t_complex_cl	z1;
	t_complex_cl	z2;
	t_complex_cl	c1;
	t_complex_cl	c2;
	t_complex_cl	t;

	double			res;
	double			tmp;
	double			abs_z;

	i = get_global_id(0) / WIDTH;
	j = get_global_id(0) % WIDTH;
	
	z.re = var.min.re + j * var.d.re;
	z.im = var.max.im - i * var.d.im;

	iter = 0;
	if (var.type == JULIA_CL)
	{
		while (sqrt(complex_abs_cl(z)) <= 4 && iter < var.max_iter)
		{
			z = complex_add_cl(complex_mult_cl(z, z), var.k);
			iter = iter + 1;
		}
	}
	else if (var.type == MANDELBROT_CL)
	{
		c1 = new_complex_cl(z.re, z.im);
		while (sqrt(complex_abs_cl(z)) <= 4 && iter < var.max_iter)
		{
			old_z = complex_mult_cl(z, z);
			z = complex_add_cl(old_z, c1);
			iter = iter + 1;
		}
	}
	else if (var.type == FROSTY_CL)
	{
		while (sqrt(complex_abs_cl(z)) <= 100 && iter < var.max_iter)
		{
			z1 = complex_add_cl(z, new_complex_cl(0.3, 0.4));
			z2 = complex_add_cl(z, new_complex_cl(-0.03, 0.04));
			z = complex_add_cl(complex_sin_cl(z1), complex_cos_cl(z2));
			iter = iter + 1;
		}
	}
	else if (var.type == RADIOLARIA_CL)
	{
		while (complex_abs_cl(z) <= 1000 && iter < var.max_iter)
		{
            old_z = z;
            z.re = old_z.re * old_z.re * old_z.re - 3 * old_z.re * old_z.im * old_z.im + 0.5;
            z.im = 3 * old_z.re * old_z.re * old_z.im - old_z.im * old_z.im * old_z.im;
			iter = iter + 1;
        }
	}
	else if (var.type == SPIDER_CL)
	{
		c1 = z;
		while (sqrt(complex_abs_cl(z)) <= 4 && iter < var.max_iter)
        {
			old_z = complex_mult_cl(z, z);
			z = complex_add_cl(old_z, c1);
			c1.re = c1.re / 2 + z.re;
			c1.im = c1.im / 2 + z.im;
			iter = iter + 1;
        }
	}
	else if (var.type == BURNING_SHIP_CL)
	{
		c1 = z;
		while (sqrt(complex_abs_cl(z)) <= 16 && iter < var.max_iter)
		{
			old_z = z;
            z.re = old_z.re * old_z.re - old_z.im * old_z.im + c1.re;
            z.im = -2 * fabs(old_z.re * old_z.im) + c1.im;
			iter = iter + 1;
		}
	}
	else if (var.type == NEWTON_CL)
	{
		while (iter < var.max_iter)
		{
			t = complex_div_cl(func_cl(z, 0), func_cl(z, 1));
			z = complex_add_cl(z, new_complex_cl(-t.re, -t.im));
			t_complex_cl root1 = new_complex_cl(1.0, 0.0);
			t_complex_cl root2 = new_complex_cl(-0.5, 0.86602540378);
			t_complex_cl root3 = new_complex_cl(-0.5, -0.86602540378);
			z1.re = z.re - root1.re;
			z1.im = z.im - root1.im;
			res = sqrt(complex_abs_cl(z1));
			z2.re = z.re - root2.re;
			z2.im = z.im - root2.im;
			tmp = sqrt(complex_abs_cl(z2));
			if (tmp < res)
				res = tmp;
			z1.re = z.re - root3.re;
			z1.im = z.im - root3.im;
			tmp = sqrt(complex_abs_cl(z1));
			if (tmp < res)
				res = tmp;
			if (res < 0.000001)
				break ;
			iter = iter + 1;
		}
	}
	else if (var.type == NOVA_CL)
	{
		c1.re = -z.im;
		c1.im = z.re;
		z.re = 1.0;
		z.im = 0.0;
		while (iter < var.max_iter)
		{
			old_z = z;
			c2 = complex_div_cl(func_cl(z, 0), func_cl(z, 1));
			t = new_complex_cl(-c2.re, -c2.im);
			c2 = complex_add_cl(z, t);
			z = complex_add_cl(c2, c1);
			z1.re = z.re - old_z.re;
			z1.im = z.im - old_z.im;
			res = sqrt(complex_abs_cl(z1));
			if (res < 0.0005)
				break ;
			iter = iter + 1;
		}
		
	}
	
	abs_z = sqrt(complex_abs_cl(z));
	if (var.color == DARK_BLUE_CL)
		col = dark_blue(iter, var.max_iter);
	else if (var.color == DARK_RED_CL)
		col = dark_red(iter, var.max_iter);
	else if (var.color == SEA_CL)
		col = sea_color(iter, var.max_iter);
	else if (var.color == RAINBOW_COLOR_CL)
		col = rainbow_scheme(iter, var.max_iter, abs_z);
	else if (var.color == BLACK_AND_WHITE_CL)
		col = black_and_white_scheme(iter, var.max_iter, abs_z);
	else if (var.color == GRAY_SCALE_CL)
		col = gray_scale(iter, var.max_iter);
	else if (var.color == FROM_YELLOW_CL)
		col = from_yellow_to_white(iter, var.max_iter, abs_z);
	else if (var.color == BLUE_CL)
		col = blue_scheme(iter, var.max_iter, abs_z);
	else if (var.color == RANDOM_CL)
		col = random_scheme(iter, var.max_iter, abs_z, var.r);
	if (var.type == RADIOLARIA_CL)
	{
		if (fabs(z.re) >= 300 || fabs(z.im) >= 10000)
			out[i* WIDTH + j] = (var.color == RAD_SP_CL) ? 0xFFD700 : col;
		else
			out[i* WIDTH + j] = 0;
	}
	else
		out[i* WIDTH + j] = col;
}