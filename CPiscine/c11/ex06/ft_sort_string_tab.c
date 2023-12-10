/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:24:17 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/25 16:33:21 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_swap_str(char **arr, int a, int b)
{
	char	*t;

	t = arr[a];
	arr[a] = arr[b];
	arr[b] = t;
}

void	ft_quick_sort(int start, int end, char **arr)
{
	int		front;
	int		back;
	int		pivot;

	if (start >= end)
		return ;
	pivot = start;
	front = start + 1;
	back = end;
	while (front <= back)
	{
		while ((front <= end) && ft_strcmp(arr[pivot], arr[front]) >= 0)
			front++;
		while ((start < back) && ft_strcmp(arr[pivot], arr[back]) <= 0)
			back--;
		if (front < back)
			ft_swap_str(arr, front, back);
		else
			ft_swap_str(arr, pivot, back);
	}
	ft_quick_sort(start, back - 1, arr);
	ft_quick_sort(back + 1, end, arr);
}

void	ft_sort_string_tab(char **tab)
{
	int	len;

	len = 0;
	while (tab[len] != 0)
		len++;
	ft_quick_sort(0, len - 1, tab);
}
/*
#include <stdio.h>
int	main(int argc, char** arr)
{
	ft_sort_string_tab(arr);
	for(int i=1;i<argc;i++)
		printf("%s\n",arr[i]);
}
*/
