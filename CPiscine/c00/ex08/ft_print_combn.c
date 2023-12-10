/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:01:47 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/09 19:22:28 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_get_comb(int n, int cur_num, int cur_res, char *res_arr)
{	
	int	i;

	if (cur_num >= 10)
	{
		if (cur_res == n)
		{	
			write(1, res_arr, n);
			i = 0;
			while (i < n)
			{
				if (res_arr[i] != 10 - n + i + '0')
				{
					write(1, ", ", 2);
					break ;
				}
				i++;
			}
		}
		return ;
	}
	res_arr[cur_res] = cur_num + '0';
	ft_get_comb(n, cur_num + 1, cur_res + 1, res_arr);
	ft_get_comb(n, cur_num + 1, cur_res, res_arr);
}

void	ft_print_combn(int n)
{
	char	res_arr[10];

	ft_get_comb(n, 0, 0, res_arr);
}
