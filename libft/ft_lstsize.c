/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:10:04 by tlam              #+#    #+#             */
/*   Updated: 2023/11/10 17:14:34 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*elem;

	i = 0;
	elem = lst;
	if (elem == NULL)
	{
		return (0);
	}
	while (elem != NULL)
	{
		i++;
		elem = elem->next;
	}
	return (i);
}
