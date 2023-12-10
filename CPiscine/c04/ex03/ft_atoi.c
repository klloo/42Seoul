/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:24:53 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/15 21:52:07 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_number(char c)
{
	return ('0' <= c && c <= '9');
}

int	ft_atoi(char *str)
{
	int	sign;
	int	res;

	sign = 1;
	while (*str == 32 || (9 <= *str && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	res = 0;
	while (ft_is_number(*str))
	{
		res = res * 10 + ((*str - '0') * sign);
		str++;
	}
	return (res);
}
