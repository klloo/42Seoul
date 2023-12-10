/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:52:18 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/19 15:04:57 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

int	stack(int *condition);

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	clue(char *s, int *result)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(s) != 31)
		return (0);
	while (j < 16)
	{
		if ((s[i] > '0' && s[i] < '5') && (s[i + 1] == 32 || s[i + 1] == '\0'))
		{
			result[j] = s[i] - '0';
			i += 2;
			j++;
		}
		else
			return (0);
	}
	return (1);
}

int	main(int ac, char *av[])
{
	int	condition[16];
	int	check;
	int	flag;

	if (ac != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	check = clue(av[1], condition);
	if (check == 1)
	{
		flag = stack(condition);
		if (flag == 0)
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
