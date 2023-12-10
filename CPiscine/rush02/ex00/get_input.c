/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:51:24 by jooahn            #+#    #+#             */
/*   Updated: 2023/02/26 23:32:20 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "str_convert.h"

char	*get_input(char *str)
{
	int		idx;
	char	*result;
	int		result_idx;
	int		size;

	init_get_input(&idx, &result_idx);
	if (!(is_num(str[idx])))
		return (0);
	while (str[idx] == '0')
		idx++;
	size = get_num_len(str + idx);
	result = (char *)malloc(sizeof(char) * size + 1);
	if (!result)
		return (0);
	if (!is_num(str[idx]) && str[idx] == '\0')
		result[result_idx] = '0';
	while (is_num(str[idx]))
		result[result_idx++] = str[idx++];
	result[size] = '\0';
	if (str[idx] != '\0')
	{
		free(result);
		return (0);
	}
	return (result);
}

int	get_num_len(char *str)
{
	int	size;
	int	idx;
	int	cnt;

	size = 0;
	idx = 0;
	cnt = 0;
	while (is_num(str[idx]))
	{
		size++;
		idx++;
		cnt += str[idx] - '0';
	}
	if (cnt == 0)
		return (1);
	return (size);
}

int	is_space(char c)
{
	if (c == ' ' || ('\t' <= c && c <= '\r'))
		return (1);
	return (0);
}

int	is_num(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}
