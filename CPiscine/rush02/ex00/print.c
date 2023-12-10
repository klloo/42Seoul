/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:10:44 by jooahn            #+#    #+#             */
/*   Updated: 2023/02/26 22:45:04 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "str_convert.h"

int	print_error(void)
{
	char	*error_msg;

	error_msg = "Error\n";
	write(2, error_msg, get_len(error_msg));
	return (-1);
}

int	print_dict_error(void)
{
	char	*dict_error_msg;

	dict_error_msg = "Dict Error\n";
	write(2, dict_error_msg, get_len(dict_error_msg));
	return (-1);
}

void	print_str(char *str)
{
	write(1, str, get_len(str));
}

void	print_str_spc(char *str)
{
	write(1, str, get_len(str));
	write(1, " ", 1);
}
