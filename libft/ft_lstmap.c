/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdean <hdean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 22:10:18 by hdean             #+#    #+#             */
/*   Updated: 2019/09/26 20:03:12 by hdean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_free_lst(t_list *list)
{
	t_list *ptr;

	ptr = list;
	while (ptr != NULL)
	{
		ptr = list->next;
		free(list);
		list = ptr;
	}
	list = NULL;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_list;
	t_list *tmp;

	if (!lst || !f)
		return (NULL);
	tmp = f(ft_lstnew(lst->content, lst->content_size));
	if (!tmp)
		return (NULL);
	new_list = tmp;
	while (lst->next)
	{
		lst = lst->next;
		if (!(tmp->next = f(ft_lstnew(lst->content, lst->content_size))))
		{
			ft_free_lst(new_list);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (new_list);
}

/*
#include "libft.h"
static void    l_lstdel(t_list **alst)
{
    t_list *head;
    t_list *to_del;
    head = *alst;
    while (head)
    {
        to_del = head;
        head = head->next;
        free(to_del);
        to_del = NULL;
    }
    *alst = NULL;
}
t_list        *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
    t_list *new;
    t_list *head;
    if (!lst && !f)
        return (NULL);
    head = f(lst);
    new = head;
    while (lst->next)
    {
        lst = lst->next;
        head->next = f(lst);
        if (!(head->next))
        {
            l_lstdel(&new);
            return (NULL);
        }
        head = head->next;
    }
    return (new);
}*/