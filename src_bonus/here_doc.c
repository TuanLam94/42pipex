/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:15:15 by tlam              #+#    #+#             */
/*   Updated: 2024/02/08 14:15:18 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	get_here_doc(char **argv, int *fd)
{
	char	*limiter;

	close(fd[0]);
	while (1)
	{
		limiter = get_next_line(STDIN_FILENO);
		if (ft_strncmp(limiter, argv[2], ft_strlen(argv[2])) == 0
			&& ft_strlen(limiter) - 1 == ft_strlen(argv[2]))
		{
			free(limiter);
			exit(0);
		}
		write(fd[1], limiter, ft_strlen(limiter));
		free(limiter);
	}
}

void	ft_here_doc(char **argv, int argc, t_data *data)
{
	pid_t	pid;
	int		fd[2];

	if (argc < 6)
		error_msg("Error, expected atleast 5 arguments using here_doc\n", data);
	if (pipe(fd) == -1)
		error_msg("Error, pipe failed\n", data);
	pid = fork();
	if (pid == -1)
		error_msg("Error, pid failed\n", data);
	if (pid == 0)
		get_here_doc(argv, fd);
	else
	{
		close(fd[1]);
		dup2(fd[0], data->fdin);
		close(fd[0]);
		wait(NULL);
	}
}
