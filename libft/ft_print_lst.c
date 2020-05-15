#include "libft.h"

static void		ft_putstr_inp(char const *s, int i)
{
	while (*s)
		write(i, s++, 1);
}

void			ft_print_lst(t_list *start, int i)
{
	t_list *ptr;

	if (start)
	{
		ptr = start;
		while (ptr != NULL)
		{
			ft_putstr_inp(ptr->content, i);
			write(i, "\n", 1);
			ptr = ptr->next;
		}
	}
}
