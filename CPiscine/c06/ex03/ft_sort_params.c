/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:46:36 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/16 18:01:29 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int	i;

	ft_quick_sort(1, argc - 1, argv);
	i = 1;
	while (i < argc)
		ft_putstr(argv[i++]);
	return (0);
}
