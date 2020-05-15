#include "fractol.h"

int	ft_error(int key)
{
	if (key == MLX_ERROR)
		ft_putstr("\033[0;35merror:\033[0m can't open the window\n");
	else if (key == USAGE)
	{
		ft_putstr("\033[0;31musage:\033[0m ./fractol [fractal]\n");
		ft_putstr("\t\033[0;36mfractals:\033[0m");
		ft_putstr(" numbers 1 - 11 or print names:\n");
		ft_putstr("\t\t1 - julia\n\t\t2 - mandelbrot\n");
		ft_putstr("\t\t3 - frosty\n\t\t4 - radiolaria\n");
		ft_putstr("\t\t5 - spider\n\t\t6 - ship\n");
		ft_putstr("\t\t7 - newton\n\t\t8 - nova\n\t\t9 - leaf\n");
		ft_putstr("\t\t10 - jong\n\t\t11 - clifford\n");
	}
	else if (key == FRACTAL_TYPE)
		ft_putstr("\033[0;35merror:\033[0m wrong fractal type\n");
	else if (key == MALLOC)
		ft_putstr("\033[0;31merror:\033[0m malloc doesn't work\n");
	else if (key == CL_READ_ERROR)
		ft_putstr("\033[0;35merror:\033[0m can't read the file with cl code\n");
	else if (key == CL_ERROR)
		ft_putstr("\033[0;35merror:\033[0m OpenCL problem\n");
	else if (key == ERR_TREADS)
		ft_putstr("\033[0;35merror:\033[0m Problems with threads\n");
	return (1);
}
