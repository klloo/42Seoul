/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:45:58 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/26 23:31:17 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "dict.h"

char	*read_dict(char *file_name)
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
			return (0);
		len += n;
	}
	close(fd);
	fd = open(file_name, O_RDONLY);
	buf = (char *)malloc(len + 1);
	n = read(fd, buf, len);
	buf[len] = '\0';
	close(fd);
	return (buf);
}

char	*get_dict_value(char *str, int start, int end)
{
	int		i;
	int		j;
	char	*res;
	int		len;

	len = 0;
	while (is_space(str[end - 1 - len]) == 0 && str[end - 1 - len] != ':')
		len++;
	res = (char *)malloc(len + 1);
	i = end - 1;
	j = len - 1;
	while (i >= start)
	{
		if (is_space(str[i]) == 0 && str[i] != ':')
			res[j] = str[i];
		else
			break ;
		i--;
		j--;
	}
	res[len] = '\0';
	return (res);
}

char	*get_dict_key(char *str, int start)
{
	int		i;
	int		len;
	char	*res;

	i = start;
	while (is_space(str[i]))
		i++;
	while (str[i] == '0' && str[i + 1] && is_number(str[i + 1]))
		i++;
	len = get_numstr_len(str, start);
	res = get_numstr(str, i, len);
	return (res);
}

void	set_dict_value(t_dict *dict, char *dict_str, int start, int end)
{
	dict->key = get_dict_key(dict_str, start);
	dict->value = get_dict_value(dict_str, start, end);
	dict->digit = get_len(dict->key);
}

t_dict	*set_dict(char *file_name)
{
	char	*dict_str;
	int		i;
	int		idx;
	int		start;
	t_dict	*dict_arr;

	dict_str = read_dict(file_name);
	if (dict_str == 0)
		return (0);
	if (!check_is_valid_dict(dict_str))
		return (0);
	dict_arr = (t_dict *)malloc((get_cnt_line(dict_str) + 1) * sizeof(t_dict));
	init_dict_idx(&i, &idx);
	while (dict_str[i] != '\0')
	{
		start = i;
		while (dict_str[i] != '\n' && dict_str[i] != '\0')
			i++;
		set_dict_value(&dict_arr[idx++], dict_str, start, i);
		if (dict_str[i] == '\n')
			i++;
	}
	dict_arr[idx].value = 0;
	free(dict_str);
	return (dict_arr);
}
