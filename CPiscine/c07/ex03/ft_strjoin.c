/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:14:38 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/19 20:18:01 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	get_size(int size, char **strs, char *sep)
{
	int	i;
	int	res_len;
	int	sep_len;

	i = 0;
	res_len = 0;
	while (i < size)
	{
		res_len += str_len(strs[i]);
		i++;
	}
	sep_len = str_len(sep) * (size - 1);
	if (size == 0)
		res_len = -1;
	else
		res_len = res_len + sep_len;
	return (res_len + 1);
}

void	my_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		arr_size;
	char	*res;
	int		strs_idx;
	int		i;
	int		len;

	arr_size = get_size(size, strs, sep);
	res = (char *)malloc(arr_size);
	strs_idx = 0;
	i = 0;
	while (strs_idx < size)
	{
		len = str_len(strs[strs_idx]);
		my_strncpy(&res[i], strs[strs_idx], len);
		i += len;
		if (strs_idx != size - 1)
		{
			len = str_len(sep);
			my_strncpy(&res[i], sep, len);
			i += len;
		}
		strs_idx++;
	}
	return (res);
}
/*
#include <stdio.h>
int main()
{
	char *strs[5] = {"aaaa","aaaaa","aaaa"};
	printf("%s\n",ft_strjoin(0, strs, "bbbbbbb"));
}
*/
