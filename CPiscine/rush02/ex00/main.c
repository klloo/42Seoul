/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:08:11 by jooahn            #+#    #+#             */
/*   Updated: 2023/02/26 23:37:57 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_convert.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char	*numbers;
	char	*dict_name;
	t_dict	*dictionary;

	if (argc == 2)
		dict_name = "numbers.dict";
	else if (argc == 3)
		dict_name = argv[1];
	else
		return (print_error());
	numbers = get_input(argv[argc - 1]);
	if (numbers == 0)
		return (print_error());
	dictionary = set_dict(dict_name);
	if (dictionary == 0)
		return (print_dict_error());
	if (!convert(numbers, dictionary))
	{
		free(numbers);
		free_dict_arr(dictionary);
		return (print_dict_error());
	}
	free(numbers);
	free_dict_arr(dictionary);
	return (0);
}
