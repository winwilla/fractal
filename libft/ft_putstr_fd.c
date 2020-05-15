#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	if (s && fd > 0)
	{
		while (*s)
			write(fd, s++, 1);
	}
}
