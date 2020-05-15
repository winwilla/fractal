#include "fractol.h"

static int	create_window_mlx(t_fractal *fractal)
{
	return (!(fractal->image.mlx_ptr = mlx_init()) ||
		!(fractal->image.win_ptr = mlx_new_window(fractal->image.mlx_ptr,
			fractal->image.width + 375, fractal->image.height, "Fract'ol")) ||
		!(fractal->image.img_ptr = mlx_new_image(fractal->image.mlx_ptr,
			fractal->image.width, fractal->image.height)) ||
		!(fractal->image.data = mlx_get_data_addr(fractal->image.img_ptr,
			&fractal->image.bits_per_pixel, &fractal->image.line_size,
			&fractal->image.endian)));
}

static int	read_file_with_cl_code(t_fractal *fractal)
{
	int		fd;
	char	buf[10000];
	int		ret;

	fd = open("./src/init.cl", O_RDONLY);
	if (fd < 0 || read(fd, NULL, 0) == -1)
		return (ft_error(CL_READ_ERROR));
	ret = read(fd, buf, 10000);
	if (!(fractal->cl.code = ft_strnew(ret)))
	{
		close(fd);
		return (ft_error(MALLOC));
	}
	ft_strncpy(fractal->cl.code, buf, ret);
	close(fd);
	return (0);
}

static void	set_max_and_min(t_fractal *fractal)
{
	if (fractal->type == MANDELBROT || fractal->type == SPIDER)
	{
		fractal->min = new_complex(-2.0, -1.5);
		fractal->max = new_complex(1.5, 1.5);
	}
	else if (fractal->type == BURNING_SHIP)
	{
		fractal->min = new_complex(-2.1, -1.7);
		fractal->max = new_complex(1.5, 1.9);
	}
	else if (fractal->type == NOVA)
	{
		fractal->min = new_complex(-2.0, -1.5);
		fractal->max = new_complex(2.0, 2.5);
	}
	else
	{
		fractal->min = new_complex(-2.0, -2.0);
		fractal->max = new_complex(2.0, 2.0);
	}
}

void		set_init_params(t_fractal *fractal)
{
	set_max_and_min(fractal);
	fractal->d = new_complex(
		(fractal->max.re - fractal->min.re) / fractal->image.width,
		(fractal->max.im - fractal->min.im) / fractal->image.height);
	fractal->julia_motion = 1;
	fractal->k = new_complex(-0.5, 0.6);
	fractal->max_iter = (fractal->type == LEAF || fractal->type == PITER ||
						fractal->type == CLIFFORD) ? MAX_ITER_DOT : MAX_ITER;
	fractal->color = RAINBOW_COLOR;
	init_random_color(fractal);
	fractal->zoom = 1;
	if (fractal->type == LEAF)
	{
		fractal->start_point_leaf.x = WIDTH / 2;
		fractal->start_point_leaf.y = HEIGHT;
	}
	else if (fractal->type == PITER || fractal->type == CLIFFORD)
	{
		fractal->start_point_leaf.x = WIDTH / 2;
		fractal->start_point_leaf.y = HEIGHT / 2;
	}
}

void		setups_for_fractal(t_fractal *fractal)
{
	fractal->image.width = WIDTH;
	fractal->image.height = HEIGHT;
	fractal->image.bits_per_pixel = 32;
	fractal->image.endian = 0;
	fractal->image.line_size = fractal->image.width;
	fractal->gpu = 0;
	set_init_params(fractal);
	fractal->cl.pl = NULL;
	fractal->cl.dev = NULL;
	fractal->cl.context = NULL;
	fractal->cl.prog = NULL;
	fractal->cl.cq = NULL;
	fractal->cl.kernel = NULL;
	fractal->cl.buf = NULL;
	fractal->cl.buf_len = WIDTH * HEIGHT;
	if (read_file_with_cl_code(fractal))
		exit(1);
	if (create_window_mlx(fractal))
		terminate_all(MLX_ERROR, fractal);
	cl_setup(fractal);
}
