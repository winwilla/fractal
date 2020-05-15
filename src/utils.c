#include "fractol.h"

void		clear_image(t_fractal *fractal)
{
	ft_bzero(fractal->image.data,
		fractal->image.width * fractal->image.height *
		(fractal->image.bits_per_pixel / 8));
}

t_color		convert_color_int_to_rgb(unsigned color)
{
	t_color	rgb;

	rgb.blue = color & 0xFF;
	rgb.green = (color >> 8) & 0xFF;
	rgb.red = (color >> 16) & 0xFF;
	return (rgb);
}

void		init_random_color(t_fractal *fractal)
{
	fractal->random.f_red = rand() % 10;
	fractal->random.f_green = rand() % 10;
	fractal->random.f_blue = rand() % 10;
	fractal->random.p_red = rand() % 20;
	fractal->random.p_blue = rand() % 20;
	fractal->random.p_green = rand() % 20;
	fractal->random.width = rand() % 255;
	fractal->random.center = rand() % 255;
}

void		switch_color_scheme(t_fractal *fractal)
{
	fractal->color++;
	if ((fractal->color == RAD_SP_CL && fractal->type != RADIOLARIA) ||
		(fractal->color == MAX_COLOR_SCHEME))
		fractal->color = RAINBOW_COLOR;
}

int			terminate_all(int error, t_fractal *fractal)
{
	ft_error(error);
	if (fractal->image.img_ptr)
		mlx_destroy_image(fractal->image.mlx_ptr, fractal->image.img_ptr);
	if (fractal->image.win_ptr)
		mlx_destroy_window(fractal->image.mlx_ptr, fractal->image.win_ptr);
	if (fractal->cl.context)
		clReleaseContext(fractal->cl.context);
	if (fractal->cl.cq)
		clReleaseCommandQueue(fractal->cl.cq);
	if (fractal->cl.prog)
		clReleaseProgram(fractal->cl.prog);
	if (fractal->cl.kernel)
		clReleaseKernel(fractal->cl.kernel);
	if (fractal->cl.buf)
		clReleaseMemObject(fractal->cl.buf);
	if (fractal->cl.code)
		ft_strdel(&(fractal->cl.code));
	exit(error);
}
