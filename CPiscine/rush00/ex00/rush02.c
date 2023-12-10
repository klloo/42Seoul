/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:12:26 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/12 18:16:42 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_write_char(int x, int y, int curx, int cury)
{
	if ((curx == 0 && cury == 0) || (curx == x - 1 && cury == 0))
		ft_putchar('A');
	else if ((curx == x - 1 && cury == y - 1) || (curx == 0 && cury == y - 1))
		ft_putchar('C');
	else if (curx == 0 || curx == x - 1 || cury == 0 || cury == y - 1)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int		i;
	int		j;
	char	*error_msg;

	error_msg = "no negative.\n";
	if ((x < 0) || (y < 0))
	{
		i = 0;
		while (error_msg[i] != '\0')
			ft_putchar(error_msg[i++]);
		return ;
	}
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_write_char(x, y, j, i);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
