/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:44:45 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/15 14:34:40 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	dest_idx;
	unsigned int	i;

	dest_idx = 0;
	while (dest[dest_idx] != '\0')
		dest_idx++;
	i = 0;
	while (i < nb && src[i] != '\0')
	{
		dest[dest_idx] = src[i];
		dest_idx++;
		i++;
	}
	dest[dest_idx] = '\0';
	return (dest);
}
