/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:38:10 by jooahn            #+#    #+#             */
/*   Updated: 2023/02/26 23:38:08 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_convert.h"
#include <stdlib.h>
#include <unistd.h>

int	convert(char *str, t_dict *dicts)
{
	int	i;
	int	len;
	int	remain;

	if (str[0] == '0')
		return (just_zero(dicts));
	init(&i, &len, &remain, str);
	while (++i < len)
	{
		if ((len - i) % 3 == 0 && !hundred(str[i], len - i, dicts, &remain))
			return (0);
		else if ((len - i) % 3 == 2)
		{
			if (!ten(charcat(str[i], str[i + 1]), len - i, dicts, &remain))
				return (0);
			if (str[i] == '1' || str[i + 1] == '0')
				i++;
		}
		else if ((len - i) % 3 == 1 && !one(str[i], len - i, dicts, &remain))
			return (0);
		if (i < len - 1 && remain != 0)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
	return (1);
}

int	just_zero(t_dict *dicts)
{
	char	*value;

	value = get_value("0", dicts);
	if (value == 0)
		return (0);
	print_str(value);
	write (1, "\n", 1);
	return (1);
}

int	hundred(char num, int digit, t_dict *dict_arr, int *remain_num)
{
	char	*value;
	char	num_str[2];
	char	*money_unit;

	money_unit = get_value_digit(digit + 1, dict_arr);
	if (money_unit == 0)
		return (0);
	if (*remain_num > 0)
		print_str_spc(money_unit);
	*remain_num = num - '0';
	if (num == '0')
		return (1);
	num_str[0] = num;
	num_str[1] = '\0';
	value = get_value(num_str, dict_arr);
	if (value == 0)
		return (0);
	print_str_spc(value);
	value = get_value("100", dict_arr);
	if (value == 0)
		return (0);
	print_str(value);
	return (1);
}

int	ten(char *num, int digit, t_dict *dict_arr, int *remain_num)
{
	char	*key;
	char	*value;

	if (!get_value_digit(digit + 2, dict_arr))
		return (0);
	*remain_num += num[0] - '0';
	if (num[0] == '1')
	{
		value = get_value(num, dict_arr);
		if (value == 0)
			return (0);
		print_str(value);
	}
	else if (num[0] != '0')
	{
		key = charcat(num[0], '0');
		value = get_value(key, dict_arr);
		if (value == 0)
			return (0);
		print_str(value);
	}
	return (1);
}

int	one(char num, int digit, t_dict *dict_arr, int *remain_num)
{
	char	*value;
	char	num_str[2];

	if (!get_value_digit(digit + 3, dict_arr))
		return (0);
	*remain_num += num - '0';
	if (num == '0')
		return (1);
	num_str[0] = num;
	num_str[1] = '\0';
	value = get_value(num_str, dict_arr);
	if (value == 0)
		return (0);
	print_str(value);
	return (1);
}
