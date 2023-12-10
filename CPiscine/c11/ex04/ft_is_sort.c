/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:42:32 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/26 13:27:13 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	if (length == 0)
		return (1);
	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			break ;
		i++;
	}
	if (i == length - 1)
		return (1);
	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			break ;
		i++;
	}
	if (i == length - 1)
		return (1);
	return (0);
}
/*
#include <stdio.h>
int func(int a,int b)
{
	if(a < b)
		return -1;
	if(a > b)
		return 1;
	return 0;
}
int main()
{
	int tab[24] = {7,7,7,7,6,6,6,6,7,5,4,3,3,3,3,3,3,2,2,2,2,1,1,1};
	int tab2[3] = {3,3,3};
	int tab3[24] = {1,1,1,2,2,2,2,2,3,3,3,4,5,5,6,6,6,6,6,6,7,7,7,7};
	printf("%d\n",ft_is_sort(tab,0,&func));
}
*/
