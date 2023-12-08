/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:31:49 by heeyjang          #+#    #+#             */
/*   Updated: 2023/10/11 15:48:28 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	*ft_get_sorted_idx(int *arr, int *sorted_arr, int len)
{
	int	i;
	int	j;
	int	*idx_arr;

	idx_arr = (int *)malloc(sizeof(int) * len);
	if (!idx_arr)
		print_error(1);
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (arr[i] == sorted_arr[j])
			{
				idx_arr[i] = j;
				break ;
			}
		}
	}
	free(sorted_arr);
	free(arr);
	return (idx_arr);
}

int	*ft_sort_arr(int *arr, int *sorted_arr, int len, int *sorted)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len)
		sorted_arr[i] = arr[i];
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len - 1)
		{
			if (sorted_arr[j] > sorted_arr[j + 1])
			{
				ft_swap(sorted_arr + j, sorted_arr + j + 1);
				*sorted = 2;
			}
		}
		if (sorted_arr[i] == sorted_arr[i + 1])
		{
			*sorted = 1;
			break ;
		}
	}
	return (ft_get_sorted_idx(arr, sorted_arr, len));
}

int	*ft_get_idx_arr(int *arr, int len)
{
	int	sorted;
	int	*idx_arr;
	int	*sorted_arr;

	sorted_arr = (int *)malloc(len * sizeof(int));
	if (!sorted_arr)
		print_error(1);
	sorted = 0;
	idx_arr = ft_sort_arr(arr, sorted_arr, len, &sorted);
	if (sorted != 2)
		print_error(sorted);
	return (idx_arr);
}

int	*ft_get_arr(int argc, char *argv[], int len)
{
	int		argc_i;
	int		arr_i;
	int		split_i;
	int		*arr;
	char	**split;

	argc_i = 1;
	arr_i = 0;
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		print_error(1);
	while (argc_i < argc)
	{
		split = ft_split(argv[argc_i], ' ');
		split_i = 0;
		while (split[split_i])
		{
			arr[arr_i++] = ft_check_integer(split[split_i]);
			split_i++;
		}
		ft_split_free(split);
		argc_i++;
	}
	arr[arr_i] = '\0';
	return (arr);
}
