/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_charset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonmiki <seonmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:33:42 by seonmiki          #+#    #+#             */
/*   Updated: 2023/03/02 02:04:48 by seonmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	get_char_start_idx(char *map_str)
{
	int	i;

	i = 0;
	while (map_str[i] != '\n' && map_str[i] != '\0')
		i++;
	if (map_str[i] == '\0' || i < 4)
		return (-1);
	return (i - 3);
}

char	*get_charset(char *map_str)
{
	int		char_start;
	char	*res;

	char_start = get_char_start_idx(map_str);
	if (char_start < 0)
		return (0);
	res = (char *)malloc(3);
	res[0] = map_str[char_start];
	res[1] = map_str[char_start + 1];
	res[2] = map_str[char_start + 2];
	return (res);
}
