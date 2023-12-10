/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:53:53 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/26 12:01:53 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	get_strlen(char	*str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*my_strdup(char *src, int n)
{
	int		i;
	char	*dest;

	dest = (char *)malloc(n + 1);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*res;

	res = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (res == 0)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		res[i].size = get_strlen(av[i]);
		res[i].str = av[i];
		res[i].copy = my_strdup(av[i], res[i].size);
		i++;
	}
	res[i].str = 0;
	return (res);
}
