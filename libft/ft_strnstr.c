/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:06:57 by heeyjang          #+#    #+#             */
/*   Updated: 2023/03/25 22:45:14 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	f;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		f = 0;
		while (haystack[i + f] != '\0' && haystack[i + f] == needle[f]
			&& i + f < len)
			f++;
		if (needle[f] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
