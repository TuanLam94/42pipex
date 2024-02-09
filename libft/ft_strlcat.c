/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:32:27 by tlam              #+#    #+#             */
/*   Updated: 2023/11/09 12:20:34 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	destlen;
	size_t	srclen;

	if (size == 0 && !dst)
		return (0);
	i = 0;
	srclen = ft_strlen(src);
	destlen = ft_strlen(dst);
	if (destlen >= size)
		return (srclen + size);
	while (src[i] && i < size - destlen - 1)
	{
		dst[destlen + i] = src[i];
		i++;
	}
	if (size > 0 && destlen < size - 1)
		dst[destlen + i] = '\0';
	return (destlen + srclen);
}
