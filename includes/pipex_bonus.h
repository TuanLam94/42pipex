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

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

typedef struct s_data
{
	char	*infile;
	char	*outfile;
	int		fdin;
	int		fdout;
	char	**env;
	int		is_heredoc;
	int		nbr_cmd;
	int		**fd;
	pid_t	*pid;
	int		heredoc_fd;
}	t_data;

void	in_out_manager(t_data *data, int i);
void	child_process(t_data *data, char **av, int i);
void	parent_process(t_data *data);
void	pipex(t_data *data, char **av);

void	ft_dup2(int fd1, int fd2, t_data *data);
void	ft_close(t_data *data);
char	*ft_getenv(char *name, char **env);
char	*get_cmd_path(char *cmd, t_data *data);
void	exec_cmd(char *cmd, t_data data);

void	get_here_doc(char **argv, int *fd);
void	ft_here_doc(char **argv, int argc, t_data *data);

void	create_tabs(t_data *data);
void	init_here_doc(int ac, char **av, char **env, t_data *data);
void	init_pipex(int ac, char **av, char **env, t_data *data);

int		ft_strcmp(char *s1, char *s2);
void	error_msg(char *msg, t_data *data);
void	free_tab(char **tab);
void	free_int_tab(int **tab, t_data data);
void	free_and_exit(t_data *data);

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
char	*ft_strdup_to_newline(char *src);

char	*join_and_free(char *stash, char *buf);
char	*clean_stash(char *stash);
int		found_newline(char *stash);
char	*read_to_stash(int fd, char *stash);
char	*get_next_line(int fd);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
