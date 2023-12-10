/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:29:05 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/25 10:48:44 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
		f(tab[i++]);
}
/*
#include <stdio.h>
void print(int a)
{
	printf("%d\n", a);
}
int main()
{
	int a[5] = {1,2,3,4,5};
	ft_foreach(a,5,&print);
}
*/
