#include "fractol.h"

static void	str_to_low(char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp)
	{
		if (ft_isalpha(*tmp))
			*tmp = ft_tolower(*tmp);
		tmp++;
	}
}

static int	choose_type(char *fractal)
{
	if (!ft_strcmp(fractal, "julia"))
		return (JULIA);
	if (!ft_strcmp(fractal, "mandelbrot"))
		return (MANDELBROT);
	if (!ft_strcmp(fractal, "frosty"))
		return (FROSTY);
	if (!ft_strcmp(fractal, "radiolaria"))
		return (RADIOLARIA);
	if (!ft_strcmp(fractal, "spider"))
		return (SPIDER);
	if (!ft_strcmp(fractal, "ship"))
		return (BURNING_SHIP);
	if (!ft_strcmp(fractal, "newton"))
		return (NEWTON);
	if (!ft_strcmp(fractal, "leaf"))
		return (LEAF);
	if (!ft_strcmp(fractal, "nova"))
		return (NOVA);
	if (!ft_strcmp(fractal, "jong"))
		return (PITER);
	if (!ft_strcmp(fractal, "clifford"))
		return (CLIFFORD);
	return (0);
}

static int	find_type(char *fractal)
{
	int		type;
	char	*tmp;

	type = ft_atoi(fractal);
	if (type >= JULIA && type <= FRACTALLS_AT_ALL)
		return (type);
	if (!type)
	{
		while (*fractal && ft_isspace(*fractal))
			fractal++;
		tmp = fractal;
		while (*tmp && !ft_isspace(*tmp))
			tmp++;
		if (*tmp)
			*tmp = '\0';
		str_to_low(fractal);
		return (choose_type(fractal));
	}
	return (0);
}

static int	check_params(char **av, int *type)
{
	*type = find_type(av[1]);
	if (*type == 0)
	{
		ft_error(FRACTAL_TYPE);
		return (ft_error(USAGE));
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_fractal fractal;

	if (ac != 2)
		return (ft_error(USAGE));
	else
	{
		if (check_params(av, &fractal.type))
			return (1);
		setups_for_fractal(&fractal);
		draw_fractal(&fractal);
		mlx_hook(fractal.image.win_ptr, 2, (1L << 2), key_press, &fractal);
		mlx_hook(fractal.image.win_ptr, 17, (1L << 17), close_hook, &fractal);
		mlx_hook(fractal.image.win_ptr, 4, 0, zoom_wheel, &fractal);
		mlx_hook(fractal.image.win_ptr, 5, 0, left_mouse_press, &fractal);
		mlx_hook(fractal.image.win_ptr, 6, 0, julia_motion, &fractal);
		mlx_loop(fractal.image.mlx_ptr);
	}
	return (0);
}
