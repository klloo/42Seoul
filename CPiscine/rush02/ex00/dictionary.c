/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:01:28 by jooahn            #+#    #+#             */
/*   Updated: 2023/02/26 22:40:20 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

char	*get_value_digit(int digit, t_dict *dict_arr)
{
	int	idx;

	idx = 0;
	while (dict_arr[idx].value != 0)
	{
		if (digit == dict_arr[idx].digit)
			return (dict_arr[idx].value);
		idx++;
	}
	return (0);
}

char	*get_value(char *key, t_dict *dict_arr)
{
	int	idx;

	idx = 0;
	while (dict_arr[idx].value != 0)
	{
		if (ft_strcmp(key, dict_arr[idx].key) == 0)
			return (dict_arr[idx].value);
		idx++;
	}
	return (0);
}
