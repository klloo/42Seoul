/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:18:42 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/23 13:33:24 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	num;
	int	i;

	if (min >= max)
		return (0);
	size = max - min;
	*range = (int *)malloc(size * 4);
	num = min;
	i = 0;
	while (num < max)
	{
		(*range)[i] = num;
		i++;
		num++;
	}
	return (size);
}

#include <stdio.h>
int main(int c, char **v)
{
	(void) c;
	int min = atoi(v[1]);
	int max = atoi(v[2]);
	int *arr;
	int size = ft_ultimate_range(&arr, min, max);
	for(int i=0;i<size;i++)
		printf("%d\n", arr[i]);
}
