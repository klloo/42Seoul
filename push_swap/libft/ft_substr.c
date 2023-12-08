/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:58:54 by heeyjang          #+#    #+#             */
/*   Updated: 2023/03/25 22:45:16 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;
	size_t			s_len;
	size_t			size;

	s_len = ft_strlen(s);
	size = len;
	if (s_len < start)
		size = 0;
	else if (s_len - start < len)
		size = s_len - start;
	substr = (char *)malloc(size + 1);
	if (!substr)
		return (0);
	i = 0;
	while (s_len >= start && i < len && s[i + start])
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = 0;
	return (substr);
}
