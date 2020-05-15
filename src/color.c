#include "fractol.h"

t_color	rainbow_scheme(int i, int i_max, double abs_z)
{
	t_color_params p;

	p.f_red = 0.4;
	p.f_green = 0.3;
	p.f_blue = 0.1;
	p.p_red = 2;
	p.p_green = 2 * M_PI_2;
	p.p_blue = 2 * M_PI_4;
	p.width = 128;
	p.center = 127;
	if (i == i_max)
		return (convert_color_int_to_rgb(BLACK));
	return (smooth_color(p, i, abs_z, 2.0));
}

t_color	black_and_white_scheme(int i, int i_max, double abs_z)
{
	t_color_params p;

	p.f_red = 0.33;
	p.f_green = 0.33;
	p.f_blue = 0.33;
	p.p_red = 0;
	p.p_green = 0;
	p.p_blue = 0;
	p.width = 128;
	p.center = 127;
	if (i >= i_max)
		return (convert_color_int_to_rgb(BLACK));
	return (smooth_color(p, i, abs_z, 2.0));
}

t_color	from_yellow_to_inf_scheme(int i, int i_max, double abs_z)
{
	t_color_params p;

	p.f_red = 0.1;
	p.f_green = 0.2;
	p.f_blue = 0.3;
	p.p_red = 0;
	p.p_green = 0;
	p.p_blue = 0;
	p.width = 128;
	p.center = 127;
	if (i >= i_max)
		return (convert_color_int_to_rgb(BLACK));
	return (smooth_color(p, i, abs_z, 2.0));
}

t_color	blue_scheme(int i, int i_max, double abs_z)
{
	t_color_params p;

	p.f_red = 1.1;
	p.f_green = 5.2;
	p.f_blue = 3.3;
	p.p_red = 0;
	p.p_green = 2;
	p.p_blue = 4;
	p.width = 127;
	p.center = 128;
	if (i >= i_max)
		return (convert_color_int_to_rgb(BLACK));
	return (smooth_color(p, i, abs_z, 2.0));
}

t_color	random_scheme(int i, int i_max, double abs_z, t_color_params p)
{
	if (i >= i_max)
		return (convert_color_int_to_rgb(BLACK));
	return (smooth_color(p, i, abs_z, 2.0));
}
