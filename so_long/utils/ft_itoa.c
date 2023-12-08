/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:37:35 by heeyjang          #+#    #+#             */
/*   Updated: 2023/12/08 16:40:45 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_get_num_len(int num)
{
	int	len;

	len = 0;
	while (num / 10 != 0)
	{
		len++;
		num /= 10;
	}
	len++;
	if (num < 0)
		len++;
	return (len);
}

static int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

char	*ft_itoa(int n)
{
	int		i;
	int		num_len;
	char	*res;

	num_len = ft_get_num_len(n);
	res = (char *)malloc(num_len + 1);
	if (!res)
		return (0);
	if (n < 0)
		res[0] = '-';
	i = num_len;
	res[i] = '\0';
	i--;
	while (n / 10 != 0)
	{
		res[i] = ft_abs(n % 10) + '0';
		n /= 10;
		i--;
	}
	res[i] = ft_abs(n % 10) + '0';
	return (res);
}
