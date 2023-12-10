/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:22:29 by heeyjang          #+#    #+#             */
/*   Updated: 2023/03/02 02:31:12 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	main(int ac, char **av)
{
	t_map_info	map_info;
	int			i;

	if (ac == 1)
	{
		map_info = get_map_info_std();
		if (map_info.row_size == -1)
			print_error();
		else
			ft_bsq(map_info);
	}
	else
	{
		i = 0;
		while (++i < ac)
		{
			map_info = get_map_info(av[i]);
			if (map_info.row_size == -1)
				print_error();
			else
				ft_bsq(map_info);
		}
	}
	return (0);
}
