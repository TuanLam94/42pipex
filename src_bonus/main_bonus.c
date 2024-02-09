/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:03:14 by tlam              #+#    #+#             */
/*   Updated: 2024/01/22 15:03:15 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	in_out_manager(t_data *data, int i)
{
	if (i == 0)
		ft_dup2(data->fdin, STDIN_FILENO, data);
	else
		ft_dup2(data->fd[i - 1][0], STDIN_FILENO, data);
	if (i == data->nbr_cmd - 1)
		ft_dup2(data->fdout, STDOUT_FILENO, data);
	else
		ft_dup2(data->fd[i][1], STDOUT_FILENO, data);
}

void	child_process(t_data *data, char **av, int i)
{
	in_out_manager(data, i);
	ft_close(data);
	if (data->is_heredoc == 0)
		exec_cmd(av[i + 2], *data);
	else
		exec_cmd(av[i + 3], *data);
}

void	parent_process(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_cmd)
		waitpid(data->pid[i], NULL, 0);
}

void	pipex(t_data *data, char **av)
{
	int	i;

	i = 0;
	while (i < data->nbr_cmd)
	{
		if (i != data->nbr_cmd - 1)
			if (pipe(data->fd[i]) == -1)
				error_msg("Error, pipe failed\n", data);
		data->pid[i] = fork();
		if (data->pid[i] == -1)
			free_and_exit(data);
		if (data->pid[i] == 0)
			child_process(data, av, i);
		i++;
	}
	ft_close(data);
	parent_process(data);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	if (ac < 5)
		error_msg("Error, expected atleat 4 arguments\n", &data);
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		init_here_doc(ac, av, env, &data);
		ft_here_doc(av, ac, &data);
	}
	else
		init_pipex(ac, av, env, &data);
	pipex(&data, av);
	free_and_exit(&data);
	return (0);
}
