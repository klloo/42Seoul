/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:54:24 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/25 10:48:26 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char *))
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		if (f(tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
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
	char *arr[4] = {"asdf","1asdf","1234", NULL};
	printf("%d\n",ft_any(arr, &func));
}
*/
