/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:39:02 by heeyjang          #+#    #+#             */
/*   Updated: 2023/12/08 16:42:20 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

char	*ft_read_line(int fd, char **pre)
{
	char	*buf;
	char	*tmp;
	int		n;

	n = 1;
	buf = (char *)malloc(BUFFER_SIZE + 1);
	while (n)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1 || !n)
			break ;
		buf[n] = 0;
		tmp = *pre;
		*pre = ft_gnl_strjoin(tmp, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free_ptr(&buf);
	if (n == -1)
	{
		free_ptr(pre);
		return (NULL);
	}
	return (*pre);
}

char	*ft_get_line(char *str)
{
	int		end;
	char	*res;

	end = 0;
	while (str[end] && str[end++] != '\n')
		;
	res = ft_substr(str, 0, end);
	return (res);
}

char	*ft_get_pre(char *str)
{
	int		len;
	int		start;
	char	*res;

	len = ft_strlen(str);
	start = 0;
	while (str[start] && str[start] != '\n')
		start++;
	if (start >= len - 1)
		return (NULL);
	res = ft_substr(str, start + 1, len - start);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*pre;
	char		*line;
	char		*res;

	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0)
		return (NULL);
	res = ft_read_line(fd, &pre);
	if (!res)
		return (NULL);
	line = ft_get_line(res);
	pre = ft_get_pre(res);
	free_ptr(&res);
	if (!line)
	{
		free_ptr(&pre);
		return (NULL);
	}
	return (line);
}
