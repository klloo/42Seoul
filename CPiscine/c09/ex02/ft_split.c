/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:17:58 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/23 14:01:02 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	ft_is_delimiter(char c, char *charset)
{
	int	i;
	int	charset_len;

	i = 0;
	charset_len = 0;
	while (charset[charset_len] != '\0')
		charset_len++;
	while (i < charset_len)
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_get_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_get_word_cnt(char *str, char *charset)
{
	int	i;
	int	cnt;
	int	flag;
	int	len;

	i = 0;
	cnt = 0;
	len = ft_get_strlen(str);
	while (i < len)
	{
		flag = 0;
		while (ft_is_delimiter(str[i], charset))
		{
			flag++;
			i++;
		}
		if ((flag > 0) && (i - flag != 0) && (str[i] != '\0'))
			cnt++;
		else if ((i - flag == 0) && (str[i] == '\0'))
			return (0);
		else
			i++;
	}
	return (cnt + 1);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		idx;
	int		start;

	res = (char **)malloc((ft_get_word_cnt(str, charset) + 1) * sizeof(char *));
	i = 0;
	idx = 0;
	while (idx < ft_get_word_cnt(str, charset))
	{
		while (ft_is_delimiter(str[i], charset) && str[i] != '\0')
			i++;
		start = i;
		while (!ft_is_delimiter(str[i], charset) && str[i] != '\0')
			i++;
		if (i - start > 0)
		{
			res[idx] = (char *)malloc((i - start) + 1);
			ft_strncpy(res[idx++], str + start, i - start);
		}
		i++;
	}
	res[idx] = NULL;
	return (res);
}

#include <stdio.h>
int main(int c, char **v)
{
	(void) c;
	char **str = ft_split(v[1], v[2]);
	int len = ft_get_word_cnt(v[1], v[2]);
	for(int i=0;i<len;i++)
		printf("%s\n",str[i]);
}

