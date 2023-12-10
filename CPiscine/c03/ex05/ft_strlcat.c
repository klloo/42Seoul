/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:44:14 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/15 19:52:03 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_get_len(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;

	dest_len = ft_get_len(dest);
	src_len = ft_get_len(src);
	if (size <= dest_len)
		return (src_len + size);
	i = 0;
	while (src[i] != 0 && dest_len + i + 1 < size)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = 0;
	return (dest_len + src_len);
}
