/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:59:40 by tlam              #+#    #+#             */
/*   Updated: 2024/02/07 16:59:41 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	create_tabs(t_data *data)
{
	int		**fd;
	pid_t	*pids;
	int		i;

	fd = malloc(sizeof(int *) * (data->nbr_cmd));
	if (!fd)
		error_msg("malloc failed\n", data);
	i = 0;
	while (i < data->nbr_cmd - 1)
	{
		fd[i] = malloc(sizeof(int) * 2);
		if (!fd[i])
			error_msg("malloc failed\n", data);
		fd[i][0] = -1;
		fd[i][1] = -1;
		i++;
	}
	pids = malloc(sizeof(pid_t) * (data->nbr_cmd));
	if (!pids)
		error_msg("malloc failed\n", data);
	data->fd = fd;
	data->pid = pids;
}

void	init_here_doc(int ac, char **av, char **env, t_data *data)
{
	data->infile = ft_strdup(av[1]);
	data->outfile = ft_strdup(av[ac - 1]);
	data->fdin = open(data->infile, O_RDWR | O_CREAT, 0644);
	if (data->fdin == -1)
		error_msg("No such file or directory\n", data);
	data->fdout = open(data->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	data->env = env;
	data->nbr_cmd = ac - 4;
	data->is_heredoc = 1;
	create_tabs(data);
}

void	init_pipex(int ac, char **av, char **env, t_data *data)
{
	data->infile = ft_strdup(av[1]);
	data->outfile = ft_strdup(av[ac - 1]);
	data->fdin = open(data->infile, O_RDONLY);
	if (data->fdin == -1)
		error_msg("No such file or directory\n", data);
	data->fdout = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	data->env = env;
	data->nbr_cmd = ac - 3;
	data->is_heredoc = 0;
	create_tabs(data);
}
