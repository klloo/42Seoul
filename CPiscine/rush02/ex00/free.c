/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 21:57:59 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/26 22:42:02 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dict.h"

void	free_dict_arr(t_dict *dict)
{
	int	i;

	i = 0;
	while (dict[i].value != 0)
	{
		free(dict[i].key);
		free(dict[i].value);
		i++;
	}
	free(dict);
}
