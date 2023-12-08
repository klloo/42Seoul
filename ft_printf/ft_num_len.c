/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 22:30:52 by heeyjang          #+#    #+#             */
/*   Updated: 2023/04/02 14:45:13 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_num_len(int num)
{
	int	len;

	len = 0;
	while (num / 10 != 0)
	{
		len++;
		num /= 10;
	}
	len++;
	if (num < 0)
		len++;
	return (len);
}

int	ft_get_unsinged_len(size_t num, int base)
{
	int	len;

	len = 0;
	while (num / base != 0)
	{
		len++;
		num /= base;
	}
	len++;
	return (len);
}
