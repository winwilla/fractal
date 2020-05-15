#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;

	i = start;
	if (!s || !(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[i] && i < len + start)
	{
		ptr[i - start] = s[i];
		i++;
	}
	ptr[i - start] = '\0';
	return (ptr);
}
