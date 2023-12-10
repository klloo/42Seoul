/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:12:23 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/21 13:16:57 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*res;
	int	i;
	int	num;

	if (min >= max)
		return (NULL);
	size = max - min;
	res = (int *)malloc(4 * size);
	i = 0;
	num = min;
	while (num + i < max)
	{
		res[i] = num + i;
		i++;
	}
	return (res);
}
