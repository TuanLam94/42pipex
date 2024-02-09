/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:52:48 by tlam              #+#    #+#             */
/*   Updated: 2023/11/13 15:52:49 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;
	t_list	*next;

	if (!lst)
		return ;
	elem = *lst;
	if (elem == NULL || del == NULL)
		return ;
	while (elem != NULL)
	{
		next = elem->next;
		del(elem->content);
		free(elem);
		elem = next;
	}
	*lst = NULL;
}
