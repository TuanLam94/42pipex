/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:41:25 by tlam              #+#    #+#             */
/*   Updated: 2024/01/23 13:41:26 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	error_msg(char *msg, t_data *data)
{
	write (2, msg, ft_strlen(msg));
	free_and_exit(data);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	free_and_exit(t_data *data)
{
	free(data->infile);
	free(data->outfile);
	free_tab(data->cmd1);
	free_tab(data->cmd2);
	exit(0);
}
