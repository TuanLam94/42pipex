/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:24:32 by tlam              #+#    #+#             */
/*   Updated: 2023/11/08 11:24:34 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*dest;

	if (!s1)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && is_set(set, s1[i]))
		i++;
	while (j > i && is_set(set, s1[j - 1]))
		j--;
	dest = malloc(sizeof(char) * (j - i + 1));
	if (!dest)
		return (NULL);
	k = 0;
	while (i < j)
		dest[k++] = s1[i++];
	dest[k] = '\0';
	return (dest);
}
