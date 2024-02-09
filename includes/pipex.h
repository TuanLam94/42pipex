/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlam <tlam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:24:45 by tlam              #+#    #+#             */
/*   Updated: 2024/01/23 12:24:46 by tlam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <errno.h>

typedef struct s_data
{
	char	*infile;
	char	*outfile;
	char	**cmd1;
	char	**cmd2;
	char	**env;
	int		fd[2];
}	t_data;

void	child_process(t_data *data);
void	parent_process(t_data *data);
void	init_pipex(char **argv, char **env, t_data *data);

void	exec_cmd(t_data data, int type);
char	*ft_getenv(char *name, char **env);
char	*get_cmd_path(char *cmd, t_data *data);

int		ft_strcmp(char *s1, char *s2);
void	error_msg(char *msg, t_data *data);
void	free_tab(char **tab);
void	free_and_exit(t_data *data);

// char	*ft_strdup(const char *s);
// int	ft_strncmp(const char *s1, const char *s2, size_t n);
// char	**ft_split(char const *s, char c)

#endif
