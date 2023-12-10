/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_condition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 10:54:23 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/19 15:19:00 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ud(int board[][6])
{
	int	cur_c;
	int	i;
	int	j;
	int	can_see;

	cur_c = 1;
	while (cur_c <= 4)
	{
		can_see = 0;
		i = 1;
		while (i <= 4)
		{
			j = 1;
			while (j <= i)
				if (board[j++][cur_c] > board[i][cur_c])
					break ;
			if (j > i)
				can_see++;
			i++;
		}
		if (board[0][cur_c++] != can_see)
			return (0);
	}
	return (1);
}

int	du(int board[][6])
{
	int	cur_c;
	int	i;
	int	j;
	int	can_see;

	cur_c = 1;
	while (cur_c <= 4)
	{
		can_see = 0;
		i = 4;
		while (i >= 1)
		{
			j = 4;
			while (j >= i)
				if (board[j--][cur_c] > board[i][cur_c])
					break ;
			if (j < i)
				can_see++;
			i--;
		}
		if (board[5][cur_c++] != can_see)
			return (0);
	}
	return (1);
}

int	lr(int board[][6])
{
	int	cur_r;
	int	i;
	int	j;
	int	can_see;

	cur_r = 1;
	while (cur_r <= 4)
	{
		can_see = 0;
		i = 1;
		while (i <= 4)
		{
			j = 1;
			while (j <= i)
				if (board[cur_r][j++] > board[cur_r][i])
					break ;
			if (j > i)
				can_see++;
			i++;
		}
		if (board[cur_r++][0] != can_see)
			return (0);
	}
	return (1);
}

int	rl(int board[][6])
{
	int	cur_r;
	int	i;
	int	j;
	int	can_see;

	cur_r = 1;
	while (cur_r <= 4)
	{
		can_see = 0;
		i = 4;
		while (i >= 1)
		{
			j = 4;
			while (j >= i)
				if (board[cur_r][j--] > board[cur_r][i])
					break ;
			if (j < i)
				can_see++;
			i--;
		}
		if (board[cur_r++][5] != can_see)
			return (0);
	}
	return (1);
}

int	is_valid_pos(int r, int c, int num, int board[][6])
{
	int	i;

	i = 1;
	while (i < r)
	{
		if (board[i][c] == num)
			return (0);
		i++;
	}
	i = 1;
	while (i < c)
	{
		if (board[r][i] == num)
			return (0);
		i++;
	}
	return (1);
}
