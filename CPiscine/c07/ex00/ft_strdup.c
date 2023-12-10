/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:02:43 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/20 20:18:56 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		src_len;
	int		i;

	src_len = ft_strlen(src);
	dest = (char *)malloc(src_len + 1);
	i = 0;
	while (i <= src_len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
int main()
{
	char *src = "asdffdsafds";
	char *dest = ft_strdup(src);
	printf("src: %d dest: %d\n", ft_strlen(src), ft_strlen(dest));
	printf("%s\n",dest);
	free(dest);
}
*/
