/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:09:45 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/25 10:48:20 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			cnt++;
		i++;
	}
	return (cnt);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	func(char *a)
{
	if(a[0] == '1')
		return 0;
	return 1;
}
int main()
{
	char *arr[4] = {"asdf","sdf","1234"};
	printf("%d\n",ft_count_if(arr, 3, &func));
}
*/
