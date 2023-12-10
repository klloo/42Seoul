/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_box.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:01:50 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/19 15:12:37 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ud(int board[][6]);

int	du(int board[][6]);

int	lr(int board[][6]);

int	rl(int board[][6]);

int	is_valid_pos(int r, int c, int num, int board[][6]);

void	set_condition(int board[][6], int *condition)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		board[0][i + 1] = condition[i];
		board[5][i + 1] = condition[i + 4];
		board[1 + i][0] = condition[i + 8];
		board[1 + i][5] = condition[i + 12];
		i++;
	}
	board[0][0] = 0;
	board[0][5] = 0;
	board[5][0] = 0;
	board[5][5] = 0;
}

void	print_board(int board[][6])
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (i <= 4)
	{
		j = 1;
		while (j <= 4)
		{
			c = board[i][j] + '0';
			write(1, &c, 1);
			if (j != 4)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	set_box(int pos, int board[][6], int *flag)
{
	int	num;
	int	r;
	int	c;

	if (pos == 17)
	{
		if (ud(board) && du(board) && lr(board) && rl(board) && !(*flag))
		{
			print_board(board);
			*flag = 1;
		}
		return ;
	}
	r = ((pos - 1) / 4) + 1;
	c = pos - 4 * (r - 1);
	num = 1;
	while (num <= 4)
	{
		if (is_valid_pos(r, c, num, board) == 1)
		{
			board[r][c] = num;
			set_box(pos + 1, board, flag);
		}
		num++;
	}
}

int	stack(int *condition)
{
	int	board[6][6];
	int	flag;

	flag = 0;
	set_condition(board, condition);
	set_box(1, board, &flag);
	return (flag);
}
