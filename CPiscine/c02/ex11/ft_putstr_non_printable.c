/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:10:35 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/20 17:36:48 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_hex(unsigned char c)
{
	char	*base;

	base = "0123456789abcdef";
	ft_putchar(base[c / 16]);
	ft_putchar(base[c % 16]);
}

int	ft_is_printable(unsigned char c)
{
	return (32 <= c && c <= 126);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (ft_is_printable(*str))
			ft_putchar(*str);
		else
		{
			ft_putchar('\\');
			ft_print_hex(*str);
		}
		str++;
	}
}
