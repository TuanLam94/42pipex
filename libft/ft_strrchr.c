/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:06:07 by tlam              #+#    #+#             */
/*   Updated: 2023/11/07 14:20:24 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;
	int			count;
	int			i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			count++;
			last = (char *)&s[i];
		}
		i++;
	}
	if (count)
		return ((char *)last);
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}
