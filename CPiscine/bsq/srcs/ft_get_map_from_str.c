/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_from_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:26:26 by seonmiki          #+#    #+#             */
/*   Updated: 2023/03/02 12:08:45 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

int	check_row_col(char *map_str, int size)
{
	int		i;
	int		r;
	int		c;
	int		c_num;

	i = 0;
	while (map_str[i++] != '\n')
		;
	c_num = get_first_col_len(map_str);
	r = 0;
	while (map_str[i] != '\0')
	{
		c = 0;
		while (map_str[i++] != '\n')
			c++;
		r++;
		if (c != c_num)
			return (0);
	}
	if (r != size)
		return (0);
	return (1);
}

int	get_map_size(char *map_str)
{
	int	size;
	int	c_size;

	size = check_map_info(map_str);
	if (size == -1)
		return (-1);
	c_size = get_first_col_len(map_str);
	if (c_size <= 0)
		return (-1);
	if (check_row_col(map_str, size) == 0)
		return (-1);
	return (size);
}

int	get_first_col_len(char *map_str)
{
	int		i;
	int		c_num;

	i = 0;
	while (map_str[i++] != '\n')
		;
	c_num = 0;
	while (map_str[i++] != '\n')
		c_num++;
	return (c_num);
}

t_map_info	get_map_from_str(char *map_str)
{
	char		**map;
	int			**int_map;
	char		*char_set;
	t_map_info	map_info;

	map = get_map(map_str, 0);
	char_set = get_charset(map_str);
	map_info.row_size = get_map_size(map_str);
	map_info.col_size = get_first_col_len(map_str);
	free(map_str);
	if (map == 0)
	{
		map_info.row_size = -1;
		free(char_set);
		return (map_info);
	}
	int_map = convert_map(map, char_set, map_info.row_size, map_info.col_size);
	map_info.int_map = int_map;
	map_info.empty_c = char_set[0];
	map_info.wall_c = char_set[1];
	map_info.full_c = char_set[2];
	free_map(map);
	free(char_set);
	return (map_info);
}
