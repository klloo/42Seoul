/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:52:44 by janghuiyeon       #+#    #+#             */
/*   Updated: 2023/08/09 20:15:18 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup2_fd(int in_fd, int out_fd)
{
	dup2(out_fd, STDOUT_FILENO);
	dup2(in_fd, STDIN_FILENO);
}

void	pipex(int infile, int outfile, t_command cmd[], char **envp)
{
	int		fd[2];
	pid_t	pid[2];

	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);
	pid[0] = fork();
	if (pid[0] == -1)
		exit(EXIT_FAILURE);
	if (pid[0] == 0)
	{
		close(fd[0]);
		dup2_fd(infile, fd[1]);
		execve(cmd[0].cmd, cmd[0].args, envp);
	}
	pid[1] = fork();
	if (pid[1] == -1)
		exit(EXIT_FAILURE);
	if (pid[1] == 0)
	{
		close(fd[1]);
		dup2_fd(fd[0], outfile);
		execve(cmd[1].cmd, cmd[1].args, envp);
	}
	close(fd[0]);
	close(fd[1]);
}
