/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queen_puzzle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:06:33 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/16 17:26:30 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_int_arr(int *arr, int size)
{
	int		i;
	char	c;

	i = 0;
	while (i < size)
	{
		c = arr[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

int	ft_is_valid(int *chess, int row, int col)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (chess[i] == col)
			return (0);
		if (ft_abs(i - row) == ft_abs(chess[i] - col))
			return (0);
		i++;
	}
	return (1);
}

void	ft_put_ten_queens(int *chess, int row, int *cnt)
{
	int	i;

	if (row == 10)
	{
		ft_put_int_arr(chess, 10);
		*cnt = *cnt + 1;
		return ;
	}
	i = 0;
	while (i < 10)
	{
		if (ft_is_valid(chess, row, i))
		{
			chess[row] = i;
			ft_put_ten_queens(chess, row + 1, cnt);
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	chess[10];
	int	cnt;

	cnt = 0;
	ft_put_ten_queens(chess, 0, &cnt);
	return (cnt);
}
