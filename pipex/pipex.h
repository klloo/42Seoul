/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:05:40 by janghuiyeon       #+#    #+#             */
/*   Updated: 2023/08/12 16:14:14 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "pipex.h"
# include "libft/libft.h"
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_command
{
	char	*cmd;
	char	**args;
}	t_command;

int			ft_puterr(int my_errno);
int			ft_put_cmderr(t_command	cmd[]);
int			ft_put_fileerr(int file1, int file2);
char		*get_cmd_path(char *cmd, char **path);
void		free_cmd(t_command cmd);
char		**get_path_envp(char **envp);
t_command	get_command(char *cmd_str, char **envp);
void		dup2_fd(int in_fd, int out_fd);
void		pipex(int infile, int outfile, t_command cmd[], char **envp);
#endif