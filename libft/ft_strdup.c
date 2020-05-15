#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ptr;

	if (!(ptr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	ft_strcpy(ptr, str);
	return (ptr);
}
