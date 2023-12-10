/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:43:09 by seonmiki          #+#    #+#             */
/*   Updated: 2023/03/02 02:04:44 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	is_printable(char c)
{
	if (32 > c || c > 126)
		return (0);
	return (1);
}

int	is_in_charset(char target, char c1, char c2)
{
	if (target != c1 && target != c2)
		return (0);
	return (1);
}

int	check_charset(char *map_str, int idx)
{
	int	i;

	if (map_str[idx] == map_str[idx + 1]
		|| map_str[idx + 1] == map_str[idx + 2]
		|| map_str[idx] == map_str[idx + 2])
		return (0);
	i = idx + 3;
	while (map_str[i] != '\0')
	{
		if (map_str[i] == '\n')
		{
			i++;
			continue ;
		}
		if (!is_in_charset(map_str[i], map_str[idx], map_str[idx + 1])
			|| !is_printable(map_str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	my_atoi(char *str, int end)
{
	int			i;
	long long	result;

	i = 0;
	result = 0;
	while (i < end)
	{
		result = result * 10;
		result = result + (str[i] - '0');
		i++;
	}
	return ((int)result);
}

int	check_map_info(char *map_str)
{
	int	i;
	int	char_start;

	char_start = get_char_start_idx(map_str);
	if (char_start < 0)
		return (-1);
	if (!check_charset(map_str, char_start))
		return (-1);
	i = 0;
	while (i < char_start)
	{
		if ('0' > map_str[i] || map_str[i] > '9')
			return (-1);
		i++;
	}
	return (my_atoi(map_str, char_start));
}
