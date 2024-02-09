/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:51:17 by tlam              #+#    #+#             */
/*   Updated: 2023/11/14 16:12:24 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_memory(char **tofree)
{
	int	i;

	i = 0;
	while (tofree[i])
		free(tofree[i++]);
	free (tofree);
}

static int	countwords(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		while (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

static char	*ft_strduplicate(char const *str, char c)
{
	char	*dest;
	int		i;
	int		len;

	len = 0;
	while (str[len] != '\0' && str[len] != c)
		len++;
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len && str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	todup(char **dest, char const *s, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			dest[k] = ft_strduplicate(&s[i], c);
			if (!dest[k])
				return (0);
			k++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	dest[k] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;

	if (!s)
		return (NULL);
	dest = malloc(sizeof(char *) * (countwords(s, c) + 1));
	if (!dest)
		return (NULL);
	if (!todup(dest, s, c))
	{
		free_memory(dest);
		return (NULL);
	}
	return (dest);
}
