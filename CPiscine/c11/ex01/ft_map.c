/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:31:59 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/25 10:48:39 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*arr;

	arr = (int *)malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		arr[i] = f(tab[i]);
		i++;
	}
	return (arr);
}
/*
#include <stdio.h>
int plus1(int a)
{
	return a+1;
}
int main()
{
	int a[5] = {1,2,3,4,5};
	int *b = ft_foreach(a,5,&plus1);
	for(int i=0;i<5;i++)
		printf("%d\n",b[i]);
}
*/
