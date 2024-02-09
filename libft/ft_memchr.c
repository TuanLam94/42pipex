/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:35:52 by tlam              #+#    #+#             */
/*   Updated: 2023/11/09 12:18:53 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		c2;
	size_t				i;
	const unsigned char	*src;

	src = s;
	c2 = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (src[i] == c2)
			return ((void *)(src + i));
		i++;
	}
	return (NULL);
}
