/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:31:36 by heeyjang          #+#    #+#             */
/*   Updated: 2023/10/11 15:14:34 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_rotate_ab(t_stack *a, t_stack *b, int *a_rotate, int *b_rotate)
{
	while (*a_rotate && *b_rotate && (*a_rotate > 0 && *b_rotate > 0))
	{
		rr(a, b);
		*a_rotate = *a_rotate - 1;
		*b_rotate = *b_rotate - 1;
	}
	while (*a_rotate && *b_rotate && (*a_rotate < 0 && *b_rotate < 0))
	{
		rrr(a, b);
		*a_rotate = *a_rotate + 1;
		*b_rotate = *b_rotate + 1;
	}
}

void	ft_rotate_a(t_stack *a, int a_rotate)
{
	while (a_rotate)
	{
		if (a_rotate > 0)
		{
			ra(a);
			a_rotate--;
		}
		else
		{
			rra(a);
			a_rotate++;
		}
	}
}

void	ft_rotate_b(t_stack *b, int b_rotate)
{
	while (b_rotate)
	{
		if (b_rotate > 0)
		{
			rb(b);
			b_rotate--;
		}
		else
		{
			rrb(b);
			b_rotate++;
		}
	}
}
