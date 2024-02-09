/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:08:17 by tlam              #+#    #+#             */
/*   Updated: 2023/11/13 16:08:18 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*elem;
	t_list	*new_elem;

	new_list = NULL;
	elem = lst;
	if (elem == NULL)
		return (NULL);
	while (elem != NULL)
	{
		new_elem = ft_lstnew(f(elem->content));
		if (new_elem == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_elem);
		elem = elem->next;
	}
	return (new_list);
}
