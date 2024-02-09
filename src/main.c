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

#include "../includes/pipex.h"

void	child_process(t_data *data)
{
	int	fd;

	fd = open(data->infile, O_RDONLY);
	if (fd == -1)
	{
		perror("sh");
		free_and_exit(data);
	}
	close(data->fd[0]);
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(data->fd[1], STDOUT_FILENO);
	close(data->fd[1]);
	exec_cmd(*data, 0);
}

void	parent_process(t_data *data)
{
	int	fd;

	fd = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	close(data->fd[1]);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	dup2(data->fd[0], STDIN_FILENO);
	close(data->fd[0]);
	exec_cmd(*data, 1);
}

void	init_pipex(char **argv, char **env, t_data *data)
{
	int	fd[2];

	if (pipe(fd) == -1)
		free_and_exit(data);
	data->infile = ft_strdup(argv[1]);
	data->outfile = ft_strdup(argv[4]);
	data->cmd1 = ft_split(argv[2], ' ');
	data->cmd2 = ft_split(argv[3], ' ');
	data->env = env;
	data->fd[0] = fd[0];
	data->fd[1] = fd[1];
}

int	main(int argc, char **argv, char **env)
{
	pid_t	pid;
	t_data	data;

	if (argc != 5)
	{
		write(2, "Error, expected 4 arguments\n", 28);
		exit(0);
	}
	init_pipex(argv, env, &data);
	pid = fork();
	if (pid == -1)
		free_and_exit(&data);
	if (pid == 0)
		child_process(&data);
	else
		parent_process(&data);
	free_and_exit(&data);
	return (0);
}
