#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *str;
	char cd;

	str = (char *)s;
	cd = (char)c;
	while (*str != cd && *str)
		str++;
	if (*str == cd)
		return ((char *)str);
	return (NULL);
}
