/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:28:31 by heeyjang          #+#    #+#             */
/*   Updated: 2023/03/25 22:45:05 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_word_cnt(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{	
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			cnt++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (cnt);
}

static int	ft_check_buf(char **buf, size_t idx)
{
	size_t	i;

	if (!buf[idx])
	{
		i = 0;
		while (i < idx)
			free(buf[i++]);
		free(buf);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	idx;
	size_t	start;

	res = (char **)malloc((ft_get_word_cnt(s, c) + 1) * sizeof(char *));
	if (!res)
		return (0);
	i = 0;
	idx = 0;
	while (idx < ft_get_word_cnt(s, c))
	{
		while (c == s[i] && s[i] != '\0')
			i++;
		start = i;
		while (c != s[i] && s[i] != '\0')
			i++;
		res[idx] = (char *)malloc((i - start) + 1);
		if (!ft_check_buf(res, idx))
			return (0);
		ft_strlcpy(res[idx++], s + start, i - start + 1);
		i++;
	}
	res[idx] = 0;
	return (res);
}
