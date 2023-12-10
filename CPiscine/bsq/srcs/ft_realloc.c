/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:30:09 by seonmiki          #+#    #+#             */
/*   Updated: 2023/03/02 12:11:09 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*my_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*my_realloc(char *buf, unsigned int size)
{
	char			*new_buf;
	unsigned int	len;

	if (size == 0)
	{
		free(buf);
		return (0);
	}
	len = 0;
	while (buf[len] != '\0')
		len++;
	if (len >= size)
		return (buf);
	new_buf = (char *)malloc(size);
	if (new_buf == 0)
		return (0);
	new_buf = my_memcpy(new_buf, buf, size);
	free(buf);
	return (new_buf);
}

t_map_info	get_map_info_std(void)
{
	char	*map_str;
	int		n;
	int		len;
	int		idx;

	idx = 0;
	n = 1;
	len = 1024;
	map_str = (char *)malloc(1024);
	while (n != 0)
	{
		map_str = my_realloc(map_str, idx + len);
		n = read(0, &map_str[idx], 1024);
		len += n;
		idx += n;
	}
	map_str[idx] = '\0';
	return (get_map_from_str(map_str));
}
