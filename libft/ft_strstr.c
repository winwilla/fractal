#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int j;
	int i;
	int k;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		j = i;
		k = 0;
		while (needle[k] && haystack[j] == needle[k])
		{
			j++;
			k++;
		}
		if (k > 0 && !needle[k])
			return ((char *)(haystack));
		haystack++;
	}
	return (NULL);
}
