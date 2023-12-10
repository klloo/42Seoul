/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:28:48 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/25 20:31:23 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_getnbr_base(int nbr, char *base);

int	ft_is_space(char c)
{
	if (c == 32 || (9 <= c && c <= 13))
		return (1);
	return (0);
}

int	ft_is_valid_base(char *base)
{
	int	i;
	int	j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || ft_is_space(base[i]))
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

int	ft_get_idx(char *base, char c)
{
	int	idx;

	idx = 0;
	while (base[idx] != '\0')
	{
		if (base[idx] == c)
			return (idx);
		idx++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	res;
	int	base_len;

	if (!ft_is_valid_base(base))
		return (0);
	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	sign = 1;
	while (ft_is_space(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	res = 0;
	while (ft_get_idx(base, *str) != -1)
	{
		res = res * base_len + (ft_get_idx(base, *str) * sign);
		str++;
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	char	*res;

	if (!ft_is_valid_base(base_from) || !ft_is_valid_base(base_to))
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	res = ft_getnbr_base(num, base_to);
	return (res);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	(void) argc;
	printf("%s\n",ft_convert_base(argv[1], argv[2], argv[3]));
}

