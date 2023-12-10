/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:25:48 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/15 12:44:57 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_start(char *str, int idx)
{
	char	pre_char;

	if (idx == 0)
		return (1);
	pre_char = str[idx - 1];
	if ('a' <= pre_char && pre_char <= 'z')
		return (0);
	if ('A' <= pre_char && pre_char <= 'Z')
		return (0);
	if ('0' <= pre_char && pre_char <= '9')
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	c;
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (ft_is_start(str, i))
		{
			if ('a' <= c && c <= 'z')
				str[i] = c - 32;
		}
		else if ('A' <= c && c <= 'Z')
			str[i] = c + 32;
		i++;
	}
	return (str);
}
