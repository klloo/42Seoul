/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:28:49 by heeyjang          #+#    #+#             */
/*   Updated: 2023/03/25 22:45:16 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	end;
	size_t	start;
	size_t	i;

	end = ft_strlen(s1);
	start = 0;
	while (start < end && ft_strchr(set, s1[start]))
		start++;
	while (start < end && end > 0 && ft_strchr(set, s1[end - 1]))
		end--;
	res = (char *)malloc(end - start + 1);
	if (!res)
		return (0);
	i = 0;
	while (i + start < end)
	{
		res[i] = s1[i + start];
		i++;
	}
	res[i] = 0;
	return (res);
}
