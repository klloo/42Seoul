/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:25:41 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/16 17:32:33 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_quick_sort(int *arr, int start, int end)
{
	int	pivot;
	int	front;
	int	back;

	if (start >= end)
		return ;
	pivot = start;
	front = start + 1;
	back = end;
	while (front <= back)
	{
		while (front <= end && arr[pivot] >= arr[front])
			front++;
		while (back > start && arr[pivot] <= arr[back])
			back--;
		if (front < back)
			ft_swap(&arr[front], &arr[back]);
		else
			ft_swap(&arr[back], &arr[pivot]);
	}
	ft_quick_sort(arr, start, back - 1);
	ft_quick_sort(arr, back + 1, end);
}

void	ft_sort_int_tab(int *tab, int size)
{
	ft_quick_sort(tab, 0, size - 1);
}
