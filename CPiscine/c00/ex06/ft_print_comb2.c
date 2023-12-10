/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:01:39 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/09 16:06:59 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_num(int num)
{
	char	num_ten;
	char	num_one;

	num_ten = '0';
	num_one = '0';
	if (num != 0)
	{
		num_ten = num / 10 + '0';
		num_one = num % 10 + '0';
	}
	write(1, &num_ten, 1);
	write(1, &num_one, 1);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < 100)
	{
		j = i + 1;
		while (j < 100)
		{
			ft_print_num(i);
			write(1, " ", 1);
			ft_print_num(j);
			if (i != 98 || j != 99)
			{
				write(1, ", ", 2);
			}
			j ++;
		}
		i ++;
	}
}
