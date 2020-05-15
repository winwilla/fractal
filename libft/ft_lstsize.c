#include "libft.h"

size_t	ft_lstsize(t_list *begin_list)
{
	size_t	count;
	t_list	*tmp;

	count = 0;
	tmp = begin_list;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
