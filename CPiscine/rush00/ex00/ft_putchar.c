/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:34:11 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/12 21:03:31 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

long long	ft_atoll(char *str)
{
	int			i;
	long long	result;
	int			str_sign;

	str_sign = 1;
	i = 0;
	if (str[0] == '-')
	{
		str_sign = -1;
		i = 1;
	}
	result = 0;
	while (str[i] != '\0')
	{
		result = result * 10;
		result = result + (str[i] - '0') * str_sign;
		i++;
	}
	return (result);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
}

int	ft_is_out_of_int(char *str)
{
	int			i;
	int			len;
	long long	lln;

	i = 0;
	if (str[0] == '-')
		i = 1;
	len = 0;
	while (str[i++] != '\0')
		len++;
	if (len > 10)
		return (0);
	lln = ft_atoll(str);
	if (lln < -2147483648 || 2147483647 < lln)
		return (0);
	return (1);
}

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i = 1;
	while (str[i] != '\0')
	{
		if (('0' > str[i]) || (str[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}
