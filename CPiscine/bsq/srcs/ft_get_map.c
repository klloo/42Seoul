/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:22:52 by seonmiki          #+#    #+#             */
/*   Updated: 2023/03/02 12:05:56 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

char	*read_map(char *file_name)
{
	char	*buf;
	char	temp[1024];
	int		fd;
	int		n;
	int		len;

	fd = open(file_name, O_RDONLY);
	n = 1;
	len = 0;
	while (n != 0)
	{
		n = read(fd, temp, 1024);
		if (n == -1)
			break ;
		len += n;
	}
	close(fd);
	if (n == -1)
		return (0);
	fd = open(file_name, O_RDONLY);
	buf = (char *)malloc(len + 1);
	n = read(fd, buf, len);
	buf[len] = '\0';
	close(fd);
	return (buf);
}

t_map_info	get_map_info(char *file_name)
{
	char		*map_str;
	t_map_info	map_info;

	map_str = read_map(file_name);
	map_info.row_size = -1;
	if (map_str == 0)
		return (map_info);
	return (get_map_from_str(map_str));
}

char	*my_strdup(char *src, int n)
{
	int		i;
	char	*dest;

	dest = (char *)malloc(n + 1);
	if (!dest)
		return (0);
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**get_map(char *map_str, int i)
{
	int		size;
	int		idx;
	char	**res;
	int		c_num;

	size = get_map_size(map_str);
	if (size <= 0)
		return (0);
	while (map_str[i++] != '\n')
		;
	c_num = get_first_col_len(map_str);
	res = (char **)malloc(sizeof(char *) * (size + 1));
	if (!res)
		return (0);
	idx = 0;
	while (idx < size)
	{
		res[idx] = my_strdup(map_str + i, c_num);
		if (!res[idx++])
			return (0);
		i += (c_num + 1);
	}
	res[size] = 0;
	return (res);
}
