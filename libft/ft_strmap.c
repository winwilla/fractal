#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *ptr;
	char *start;

	start = NULL;
	if (!s || !f || !(ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	start = ptr;
	while (*s)
	{
		*ptr = f(*s);
		ptr++;
		s++;
	}
	*ptr = '\0';
	return (start);
}
