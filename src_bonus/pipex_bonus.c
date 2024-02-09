/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:14:39 by tlam              #+#    #+#             */
/*   Updated: 2024/01/23 17:14:40 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_dup2(int fd1, int fd2, t_data *data)
{	
	if (dup2(fd1, fd2) == -1)
		free_and_exit(data);
}

void	ft_close(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_cmd - 1)
	{
		if (data->fd[i][0] != -1)
		{
			close(data->fd[i][0]);
			data->fd[i][0] = -1;
		}			
		if (data->fd[i][1] != -1)
		{
			close(data->fd[i][1]);
			data->fd[i][1] = -1;
		}	
	}
	close(data->fdin);
	close(data->fdout);
}

char	*ft_getenv(char *name, char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strcmp(sub, name) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

char	*get_cmd_path(char *cmd, t_data *data)
{
	int		i;
	char	**allpath;
	char	*temp;
	char	*path;

	if (!data->env || !data->env[0])
		error_msg("Env error\n", data);
	allpath = ft_split(ft_getenv("PATH", data->env), ':');
	if (!allpath || !allpath[0])
		return (NULL);
	i = -1;
	while (allpath[++i] != NULL)
	{
		temp = ft_strjoin(allpath[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (!access(path, X_OK | F_OK))
		{
			free_tab(allpath);
			return (path);
		}
		free(path);
	}
	free_tab(allpath);
	return (NULL);
}

void	exec_cmd(char *cmd, t_data data)
{
	char	*cmd_path;
	char	**split_cmd;

	split_cmd = ft_split(cmd, ' ');
	cmd_path = get_cmd_path(split_cmd[0], &data);
	if (split_cmd == NULL || split_cmd[0] == NULL || cmd_path == NULL)
	{
		free(cmd_path);
		free_tab(split_cmd);
		error_msg("execve : Command not found\n", &data);
	}
	execve(cmd_path, split_cmd, data.env);
	free(cmd_path);
	free_tab(split_cmd);
	perror("execve");
	exit(EXIT_FAILURE);
}
