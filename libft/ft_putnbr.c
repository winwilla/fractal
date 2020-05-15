#include "libft.h"

void	ft_putnbr(int n)
{
	long int tmp;

	tmp = (long int)n;
	if (tmp < 0)
	{
		ft_putchar('-');
		tmp *= -1;
	}
	if (tmp >= 0 && tmp < 10)
		ft_putchar(tmp + '0');
	else if (tmp >= 10)
	{
		ft_putnbr(tmp / 10);
		ft_putnbr(tmp % 10);
	}
}
