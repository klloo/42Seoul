/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:29:46 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/21 13:20:02 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_get_nbr_len(int nbr, int n)
{
	int	len;

	len = 0;
	while (nbr / n != 0)
	{
		len++;
		nbr /= n;
	}
	len++;
	if (nbr < 0)
		len++;
	return (len);
}

int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

char	*ft_getnbr_base_n(int nbr, char *base, int n)
{
	int		i;
	int		num_len;
	char	*res;

	num_len = ft_get_nbr_len(nbr, n);
	res = (char *)malloc(num_len + 1);
	if (nbr < 0)
		res[0] = '-';
	i = num_len;
	res[i] = '\0';
	i--;
	while (nbr / n != 0)
	{
		res[i] = base[ft_abs(nbr % n)];
		nbr /= n;
		i--;
	}
	res[i] = base[ft_abs(nbr % n)];
	return (res);
}

char	*ft_getnbr_base(int nbr, char *base)
{
	int		base_len;
	char	*res;

	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	res = ft_getnbr_base_n(nbr, base, base_len);
	return (res);
}
