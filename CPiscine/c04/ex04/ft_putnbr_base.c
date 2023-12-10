/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:10:29 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/19 17:55:33 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_valid_base(char *base)
{
	int	i;
	int	j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

void	ft_putnbr_base_n(int nbr, char *base, int n)
{
	if (nbr / n == 0)
	{
		ft_putchar(base[ft_abs(nbr)]);
		return ;
	}
	ft_putnbr_base_n(nbr / n, base, n);
	ft_putchar(base[ft_abs(nbr % n)]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	if (!ft_is_valid_base(base))
		return ;
	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	if (nbr < 0)
		ft_putchar('-');
	ft_putnbr_base_n(nbr, base, base_len);
}
