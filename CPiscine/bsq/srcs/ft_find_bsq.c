/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_bsq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:20:46 by seonmiki          #+#    #+#             */
/*   Updated: 2023/03/02 12:46:04 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	ft_most_small(int **print, int y, int x)
{
	int	small;

	if (y == 0 || x == 0)
		return (print[y][x]);
	small = print[y - 1][x - 1];
	if (print[y - 1][x] < small)
		small = print[y - 1][x];
	if (print[y][x - 1] < small)
		small = print[y][x - 1];
	return (small);
}

int	ft_find_bsq(int **print, int *dy, int *dx, t_map_info map_info)
{
	int	max;
	int	y;
	int	x;

	max = -1;
	y = -1;
	while (++y < map_info.row_size)
	{
		x = -1;
		while (++x < map_info.col_size)
		{
			if (print[y][x] == 1)
				print[y][x] = ft_most_small(print, y, x) + 1;
			if (max < print[y][x])
			{
				max = print[y][x];
				*dy = y;
				*dx = x;
			}
		}
	}
	return (max);
}
