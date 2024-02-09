/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:19:47 by tlam              #+#    #+#             */
/*   Updated: 2023/11/09 15:08:01 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*cdest;
	const char	*csrc;

	cdest = (char *)dest;
	csrc = (const char *)src;
	if (cdest == csrc || n == 0)
		return (dest);
	if (cdest < csrc)
	{
		while (n--)
			*cdest++ = *csrc++;
	}
	else
	{
		cdest += n;
		csrc += n;
		while (n--)
			*(--cdest) = *(--csrc);
	}
	return (dest);
}
