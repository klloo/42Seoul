/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:06:10 by heeyjang          #+#    #+#             */
/*   Updated: 2023/03/25 22:45:10 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(s1);
	dest = (char *)malloc(src_len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i <= src_len)
	{
		dest[i] = s1[i];
		i++;
	}
	return (dest);
}
