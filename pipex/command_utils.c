/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:53:34 by janghuiyeon       #+#    #+#             */
/*   Updated: 2023/08/09 20:15:14 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd_path(char *cmd, char **path)
{
	char	*res_cmd;
	char	*slash_cmd;
	int		i;

	i = 0;
	slash_cmd = ft_strjoin("/", cmd);
	while (path[i])
	{
		res_cmd = ft_strjoin(path[i++], slash_cmd);
		if (access(res_cmd, X_OK) != -1)
		{
			free(slash_cmd);
			return (res_cmd);
		}
		free(res_cmd);
	}
	free(slash_cmd);
	return (0);
}

void	free_cmd(t_command cmd)
{
	int	i;

	if (cmd.cmd)
	{
		free(cmd.cmd);
		cmd.cmd = 0;
	}
	i = 0;
	while (cmd.args[i])
	{
		free(cmd.args[i]);
		cmd.args[i++] = 0;
	}
	free(cmd.args);
}

char	**get_path_envp(char **envp)
{
	char	**res;
	int		i;

	i = -1;
	while (envp[++i])
		if (!ft_strncmp("PATH", envp[i], 4))
			break ;
	res = ft_split(envp[i] + 5, ':');
	return (res);
}

t_command	get_command(char *cmd_str, char **envp)
{
	t_command	command;
	char		**path;
	int			i;

	command.cmd = 0;
	command.args = ft_split(cmd_str, ' ');
	path = get_path_envp(envp);
	if (!command.args || !path || !command.args[0])
		return (command);
	command.cmd = get_cmd_path(command.args[0], path);
	i = 0;
	while (path[i])
		free(path[i++]);
	free(path);
	if (!command.cmd)
		return (command);
	return (command);
}
