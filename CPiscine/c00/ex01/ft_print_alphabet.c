/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:53:30 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/09 15:39:27 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	int		i;
	char	res;

	i = 0;
	while (i < 26)
	{
		res = 'a' + i;
		write(1, &res, 1);
		i ++;
	}
}
