/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:44:10 by tlam              #+#    #+#             */
/*   Updated: 2023/11/08 10:44:12 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	j;
	size_t	slen;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	slen = ft_strlen(s + start);
	if (len > slen)
		len = slen;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
		dest[j++] = s[i++];
	dest[j] = '\0';
	return (dest);
}
