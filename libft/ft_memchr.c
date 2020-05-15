#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	sr;

	sr = (unsigned char)c;
	str = (unsigned char *)s;
	while (n > 0)
	{
		if (*str == sr)
			return ((void *)str);
		str++;
		n--;
	}
	return (NULL);
}
