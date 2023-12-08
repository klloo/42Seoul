/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 23:21:43 by heeyjang          #+#    #+#             */
/*   Updated: 2023/03/25 22:45:01 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		c1 = (unsigned char *)(s1 + i);
		c2 = (unsigned char *)(s2 + i);
		if (*c1 != *c2)
			break ;
		i++;
	}
	return (*c1 - *c2);
}
