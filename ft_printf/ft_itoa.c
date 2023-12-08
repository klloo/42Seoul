/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:57:53 by heeyjang          #+#    #+#             */
/*   Updated: 2023/04/02 14:57:28 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

char	*ft_get_base(char format)
{
	char	*base;

	base = 0;
	if (format == 'd' || format == 'i' || format == 'u')
		base = "0123456789";
	else if (format == 'x' || format == 'p')
		base = "0123456789abcdef";
	else if (format == 'X')
		base = "0123456789ABCDEF";
	return (base);
}

char	*ft_itoa(int num)
{
	int		i;
	int		num_len;
	char	*res;

	num_len = ft_get_num_len(num);
	res = (char *)malloc(num_len + 1);
	if (!res)
		return (0);
	if (num < 0)
		res[0] = '-';
	i = num_len;
	res[i] = '\0';
	i--;
	while (num / 10 != 0)
	{
		res[i] = ft_abs(num % 10) + '0';
		num /= 10;
		i--;
	}
	res[i] = ft_abs(num % 10) + '0';
	return (res);
}

char	*ft_itoa_unsigned_base(size_t num, int n, char *base)
{
	int		i;
	int		num_len;
	char	*res;

	num_len = ft_get_unsinged_len(num, n);
	res = (char *)malloc(num_len + 1);
	if (!res)
		return (0);
	i = num_len;
	res[i] = '\0';
	i--;
	while (num / n != 0)
	{
		res[i] = base[num % n];
		num /= n;
		i--;
	}
	res[i] = base[num % n];
	return (res);
}
