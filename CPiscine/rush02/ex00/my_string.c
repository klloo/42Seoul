/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:46:00 by jooahn            #+#    #+#             */
/*   Updated: 2023/02/26 23:34:54 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while (s1[idx] == s2[idx] && s1[idx] != '\0')
		idx++;
	return (s1[idx] - s2[idx]);
}

char	*charcat(char c1, char c2)
{
	char	result[3];
	char	*temp;

	result[0] = c1;
	result[1] = c2;
	result[2] = '\0';
	temp = result;
	return (temp);
}

int	is_number(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}
