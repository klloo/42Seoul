/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:31:46 by heeyjang          #+#    #+#             */
/*   Updated: 2023/10/11 15:19:45 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_split_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
	{
		return (1);
	}
	return (0);
}

long long	ft_atoll(const char *str)
{
	long long	result;
	int			minus;
	int			digit;

	result = 0;
	minus = 1;
	digit = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		minus = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
		digit++;
	}
	result = result * minus;
	if (*str != '\0' || digit > 10)
		result = 2147483648;
	return (result);
}

int	ft_check_integer(const char *str)
{
	long long	num;

	num = ft_atoll(str);
	if (num > 2147483647 || num < -2147483648)
		print_error(1);
	return ((int)num);
}

int	ft_get_arr_len(int argc, char *argv[])
{
	int		i;
	int		split_i;
	int		size;
	char	**split;

	i = 0;
	size = 0;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		split_i = 0;
		while (split[split_i])
			split_i++;
		size += split_i;
		ft_split_free(split);
		i++;
	}
	return (size - 1);
}
