/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:03:39 by tlam              #+#    #+#             */
/*   Updated: 2023/11/13 16:03:40 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*elem;

	elem = lst;
	if (elem == NULL)
		return ;
	while (elem != NULL)
	{
		f(elem->content);
		elem = elem->next;
	}
}
