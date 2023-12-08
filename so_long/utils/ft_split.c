/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:37:45 by heeyjang          #+#    #+#             */
/*   Updated: 2023/12/08 16:38:29 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_get_word_cnt(char const *s, char c)
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

void	ft_check_buf(char **buf, size_t idx)
{
	size_t	i;

	if (!buf[idx])
	{
		i = 0;
		while (i < idx)
			free(buf[i++]);
		free(buf);
	}
}

char	**ft_split(char *s, char c)
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
		ft_check_buf(res, idx);
		ft_strlcpy(res[idx++], s + start, i - start + 1);
		i++;
	}
	res[idx] = 0;
	return (res);
}
