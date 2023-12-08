/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:05:02 by janghuiyeon       #+#    #+#             */
/*   Updated: 2023/08/12 16:09:22 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_puterr(int my_errno)
{
	if (my_errno)
		errno = my_errno;
	perror("Error");
	return (1);
}

int	ft_put_cmderr(t_command	cmd[])
{
	int	len;
	int	i;

	i = -1;
	while (++i < 2)
	{
		if (!cmd[i].cmd)
		{
			write(2, "Error: command not found: ", 26);
			if (cmd[i].args && cmd[i].args[0])
			{
				len = ft_strlen(cmd[i].args[0]);
				write(2, cmd[i].args[0], len);
			}
			if (i == 0)
				write(2, "\n", 1);
		}
		free_cmd(cmd[i]);
	}
	return (1);
}

int	ft_put_fileerr(int file1, int file2)
{
	perror("Error");
	if (file1 != -1)
		close(file1);
	if (file2 != -1)
		close(file2);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	int			infile;
	int			outfile;
	t_command	cmd[2];

	if (argc != 5)
		return (ft_puterr(EINVAL));
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	cmd[0] = get_command(argv[2], envp);
	cmd[1] = get_command(argv[3], envp);
	if (infile < 0 || outfile < 0)
		return (ft_put_fileerr(infile, outfile));
	if (!cmd[0].cmd || !cmd[1].cmd)
		return (ft_put_cmderr(cmd));
	pipex(infile, outfile, cmd, envp);
	wait(0);
	wait(0);
	free_cmd(cmd[0]);
	free_cmd(cmd[1]);
	if (close(infile) < 0 || close(outfile) < 0)
		return (ft_puterr(0));
	return (0);
}
