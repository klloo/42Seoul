/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:34:09 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/27 14:46:50 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(char **a, char **b)
{
	char	*t;

	t = *a;
	*a = *b;
	*b = t;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	len;
	int	i;
	int	j;

	len = 0;
	while (tab[len] != 0)
		len++;
	i = len - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
				swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i--;
	}
}
/*
#include <stdio.h>
int str_len(char *str)
{
	int len = 0;
	while (str[len] != '\0')
		len++;
	return len;
}
int	ft_strcmp(char *s1, char *s2)
{
	return str_len(s1) - str_len(s2);
}
int	main(int argc, char** arr)
{
	ft_advanced_sort_string_tab(arr + 1, ft_strcmp);
	for(int i=1;i<argc;i++)
		printf("%s\n",arr[i]);
}
*/
