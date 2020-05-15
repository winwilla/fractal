#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int tmp;

	if (fd > 0)
	{
		tmp = (long int)n;
		if (tmp < 0)
		{
			ft_putchar_fd('-', fd);
			tmp *= -1;
		}
		if (tmp >= 0 && tmp < 10)
			ft_putchar_fd(tmp + '0', fd);
		else if (tmp >= 10)
		{
			ft_putnbr_fd(tmp / 10, fd);
			ft_putnbr_fd(tmp % 10, fd);
		}
	}
}
