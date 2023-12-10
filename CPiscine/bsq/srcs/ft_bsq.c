/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:18:14 by seonmiki          #+#    #+#             */
/*   Updated: 2023/03/02 12:14:58 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	ft_bsq(t_map_info map_info)
{
	int		**int_map;
	int		max;
	int		dy;
	int		dx;
	int		i;

	int_map = map_info.int_map;
	max = ft_find_bsq(int_map, &dy, &dx, map_info);
	ft_print_findmap(map_info, dy, dx, max);
	i = 0;
	while (i < map_info.row_size)
		free(int_map[i++]);
	free(int_map);
	return (1);
}
