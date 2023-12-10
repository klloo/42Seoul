/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:29:51 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/15 14:35:24 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		c1 = (unsigned char) s1[i];
		c2 = (unsigned char) s2[i];
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
