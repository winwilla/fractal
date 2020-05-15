#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*p;
	size_t	i;

	p = (char *)b;
	i = 0;
	while (i < len)
		p[i++] = c;
	return (b);
}
