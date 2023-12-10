/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 02:32:05 by jooahn            #+#    #+#             */
/*   Updated: 2023/02/26 23:32:29 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_convert.h"

void	init(int *idx, int *len, int *remain_num, char *str)
{
	*idx = -1;
	*len = get_len(str);
	*remain_num = 0;
}

void	init_dict_idx(int *i, int *idx)
{
	*i = 0;
	*idx = 0;
}

void	init_get_input(int *i, int *result_idx)
{
	*i = 0;
	*result_idx = 0;
}
