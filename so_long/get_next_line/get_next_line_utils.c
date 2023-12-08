/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:38:56 by heeyjang          #+#    #+#             */
/*   Updated: 2023/12/08 16:41:20 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			break ;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

unsigned int	ft_strlen(const char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	while (i < src_len && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (src_len);
}

char	*ft_gnl_strjoin(char *pre, char *buf)
{
	size_t	pre_len;
	size_t	buf_len;
	char	*res;

	if (!pre)
	{
		pre = (char *)malloc(1);
		if (!pre)
			return (NULL);
		pre[0] = 0;
	}
	pre_len = ft_strlen(pre);
	buf_len = ft_strlen(buf);
	res = (char *)malloc(pre_len + buf_len + 1);
	if (!res)
	{
		free_ptr(&pre);
		return (NULL);
	}
	ft_strlcpy(res, pre, pre_len + 1);
	ft_strlcpy(res + pre_len, buf, buf_len + 1);
	free_ptr(&pre);
	return (res);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
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
		return (NULL);
	i = 0;
	while (s_len >= start && i < len && s[i + start])
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = 0;
	return (substr);
}
