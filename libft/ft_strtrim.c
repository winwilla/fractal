#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char		*ptr;
	char		*start;
	char		*end;
	size_t		i;

	if (!s)
		return (NULL);
	start = (char *)s;
	end = (char *)(s + ft_strlen(s));
	while (*start && ft_isspace(*start))
		start++;
	while (start != end && ft_isspace(*--end))
		;
	if (!(ptr = ft_strnew(end - start + 1)))
		return (NULL);
	i = 0;
	while (start <= end)
		ptr[i++] = *start++;
	return (ptr);
}
