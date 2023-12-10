/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:00:28 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/26 23:22:03 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dict.h"

int	get_numstr_len(char *str, int start)
{
	int	i;
	int	len;

	i = start;
	len = 0;
	while (is_space(str[i]))
		i++;
	while (str[i] == '0' && str[i + 1] && is_number(str[i + 1]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			len++;
		i++;
	}
	if (!is_number(str[i]))
		return (1);
	while (is_number(str[i]))
	{
		i++;
		len++;
	}
	return (len);
}

char	*get_numstr(char *str, int i, int len)
{
	int		j;
	char	*res;

	res = (char *)malloc(len + 1);
	j = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			res[j++] = str[i];
		i++;
	}
	if (!is_number(str[i]))
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}	
	while (j < len)
		res[j++] = str[i++];
	res[j] = '\0';
	return (res);
}

int	get_cnt_line(char *str)
{
	int	cnt;

	cnt = 1;
	if (*str == '\0')
		return (0);
	while (*str != '\0')
	{
		if (*str == '\n')
			cnt++;
		str++;
	}
	return (cnt);
}

int	check_dict_format(char *str, int start, int end)
{
	int	i;
	int	key_i;
	int	sep_i;
	int	value_i;

	i = start;
	key_i = -1;
	sep_i = -1;
	value_i = -1;
	while (i < end)
	{
		if (key_i == -1 && !is_space(str[i]) && str[i] != ':')
			key_i = i;
		else if (str[i] == ':')
			sep_i = i;
		else if (sep_i > -1 && key_i > -1 && !is_space(str[i]) && str[i] != ':')
			value_i = i;
		i++;
	}
	if (sep_i == -1 || key_i == -1 || value_i == -1)
		return (0);
	if (!(key_i <= sep_i && sep_i <= value_i))
		return (0);
	return (1);
}

int	check_is_valid_dict(char *dict_str)
{
	int	i;
	int	start;

	i = 0;
	while (dict_str[i] != '\0')
	{
		start = i;
		while (dict_str[i] != '\n' && dict_str[i] != '\0')
			i++;
		if (!check_dict_format(dict_str, start, i))
		{
			free(dict_str);
			return (0);
		}
		if (dict_str[i] == '\n')
			i++;
	}
	return (1);
}
