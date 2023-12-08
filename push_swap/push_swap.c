/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:42:16 by heeyjang          #+#    #+#             */
/*   Updated: 2023/10/11 15:52:46 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	print_error(int errno)
{
	if (errno == 1)
		write(2, "Error\n", 6);
	exit(errno);
}

int	main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;

	if (argc < 2)
		print_error(0);
	a = init_stack();
	ft_set_stack(a, argc, argv);
	b = init_stack();
	ft_sort(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
