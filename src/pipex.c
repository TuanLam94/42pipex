/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:14:39 by tlam              #+#    #+#             */
/*   Updated: 2024/01/23 17:14:40 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

void	exec_cmd(t_data data, int type)
{
	char	*cmd_path;

	if (type == 0)
	{
		cmd_path = get_cmd_path(data.cmd1[0], &data);
		if (data.cmd1 == NULL || data.cmd1[0] == NULL || cmd_path == NULL)
			error_msg("execve : Command not found\n", &data);
		execve(cmd_path, data.cmd1, data.env);
		free(cmd_path);
		error_msg("execve : Command not found\n", &data);
	}
	else if (type == 1)
	{
		cmd_path = get_cmd_path(data.cmd2[0], &data);
		if (data.cmd2 == NULL || data.cmd2[0] == NULL || cmd_path == NULL)
			error_msg("execve : Command not found\n", &data);
		execve(cmd_path, data.cmd2, data.env);
		free(cmd_path);
		error_msg("execve : Command not found\n", &data);
	}
}
