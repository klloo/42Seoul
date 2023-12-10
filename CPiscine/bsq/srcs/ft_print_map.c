/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 00:32:27 by seonmiki          #+#    #+#             */
/*   Updated: 2023/03/02 12:17:14 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_print_findmap(t_map_info map_info, int dy, int dx, int max)
{
	int	j;
	int	k;

	j = -1;
	while (++j < map_info.row_size)
	{
		k = -1;
		while (++k < map_info.col_size)
		{
			if ((j > dy - max && j <= dy) && (k > dx - max && k <= dx))
				write(1, &map_info.full_c, 1);
			else if (map_info.int_map[j][k] == 0)
				write(1, &map_info.wall_c, 1);
			else
				write(1, &map_info.empty_c, 1);
		}
		write(1, "\n", 1);
	}
}
