/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:18:13 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/15 12:47:25 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_long_to_hex(unsigned long num, char *res)
{
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	while (i < 16)
		res[i++] = '0';
	while (num != 0 || num / 16 != 0)
	{
		res[--i] = base[num % 16];
		num /= 16;
	}
	res[--i] = base[num];
}

void	ft_print_char_hex(void *addr, int size)
{
	unsigned char	c;
	int				i;
	int				end;
	char			hex_val[16];
	char			*blank;

	i = 0;
	while (i < size)
	{
		c = *(unsigned char *)(addr + i);
		ft_long_to_hex((unsigned long) c, hex_val);
		write(1, &hex_val[14], 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	if (size < 16)
	{
		blank = "                                             ";
		end = (16 - size) * 2 + (16 - size) / 2;
		if (size % 2 == 1)
			end += 1;
		write(1, blank, end);
	}
}

void	ft_print_char(void *addr, int size)
{
	unsigned char	res;
	unsigned char	c;
	int				i;

	i = 0;
	while (i < size)
	{
		c = *(unsigned char *)(addr + i);
		res = '.';
		if (32 <= c && c <= 126)
			res = c;
		write(1, &res, 1);
		i++;
	}
}

void	ft_print_addr(void *addr)
{
	unsigned long	addr_long;
	char			hex_val[16];

	addr_long = (unsigned long) addr;
	ft_long_to_hex(addr_long, hex_val);
	write(1, hex_val, 16);
	write(1, ": ", 2);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size / 16)
	{
		ft_print_addr(addr + i * 16);
		ft_print_char_hex(addr + i * 16, 16);
		ft_print_char(addr + i * 16, 16);
		write(1, "\n", 1);
		i++;
	}
	if (size % 16)
	{
		ft_print_addr(addr + i * 16);
		ft_print_char_hex(addr + i * 16, size % 16);
		ft_print_char(addr + i * 16, size % 16);
		write(1, "\n", 1);
	}
	return (addr);
}
