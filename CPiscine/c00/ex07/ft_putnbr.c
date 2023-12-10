/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:03:03 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/09 22:47:44 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_abs(int num)
{
	if (num < 0)
	{
		return (num * -1);
	}
	return (num);
}

void	ft_putnbr(int nb)
{
	char	reversed_res[11];
	int		i;

	if (nb < 0)
	{
		write(1, "-", 1);
	}
	i = 0;
	while (nb != 0 && nb / 10 != 0)
	{
		reversed_res[i++] = ft_abs(nb % 10) + '0';
		nb = ft_abs(nb / 10);
	}
	reversed_res[i] = ft_abs(nb) + '0';
	while (i >= 0)
	{
		write(1, &reversed_res[i], 1);
		i --;
	}
}
