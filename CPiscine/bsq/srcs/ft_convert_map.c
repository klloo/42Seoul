/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:32:35 by seonmiki          #+#    #+#             */
/*   Updated: 2023/03/02 02:04:45 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	**convert_map(char **map, char *char_set, int size, int c_size)
{
	int		**res;
	int		i;
	int		j;

	res = (int **)malloc(sizeof(int *) * size);
	i = 0;
	while (i < size)
	{
		j = 0;
		res[i] = (int *)malloc(sizeof(int) * c_size);
		while (j < c_size)
		{
			if (map[i][j] == char_set[0])
				res[i][j] = 1;
			else
				res[i][j] = 0;
			j++;
		}
		i++;
	}
	return (res);
}
