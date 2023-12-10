/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:22:41 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/20 16:25:31 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	src_len;

	src_len = 0;
	i = 0;
	while (src[src_len] != '\0')
		src_len++;
	while (i < src_len && n != 0 && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (n > 0)
		dest[i] = '\0';
	return (src_len);
}
