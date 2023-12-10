/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:44:57 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/15 14:37:15 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	f;

	if (*to_find == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		f = 0;
		while (str[i + f] != '\0' && str[i + f] == to_find[f])
			f++;
		if (to_find[f] == '\0')
			return (&str[i]);
		i++;
	}
	return (0);
}
