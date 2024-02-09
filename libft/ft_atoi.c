/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:09:40 by tlam              #+#    #+#             */
/*   Updated: 2023/11/07 16:35:48 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	atoi;
	int	negative;

	atoi = 0;
	negative = 1;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t'
		|| *nptr == '\r' || *nptr == '\f' || *nptr == '\v')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			negative = -negative;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		atoi = atoi * 10 + (*nptr - 48);
		nptr++;
	}
	return (atoi * negative);
}
