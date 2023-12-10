/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:54:52 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/20 17:57:32 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	put_num(int num)
{
	char	c;

	if (num / 10 == 0)
	{
		c = num % 10 + '0';
		write(1, &c, 1);
		return ;
	}
	put_num(num / 10);
	c = num % 10 + '0';
	write(1, &c, 1);
}

void	put_str(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		put_str(par[i].str);
		put_num(par[i].size);
		write(1, "\n", 1);
		put_str(par[i].copy);
		i++;
	}
}
/*
#include <stdio.h>
struct s_stock_str *ft_strs_to_tab(int ac, char **av);
int main(int argc, char *argv[])
{
	t_stock_str *st;
	st = ft_strs_to_tab(argc, argv);
	ft_show_tab(st);
}
*/
