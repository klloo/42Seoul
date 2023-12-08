/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:30:47 by heeyjang          #+#    #+#             */
/*   Updated: 2023/10/11 15:14:35 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size < 2)
	{
		return ;
	}
	tmp = stack->bottom;
	stack->bottom = stack->bottom->prev;
	stack->bottom->next = NULL;
	stack->top->prev = tmp;
	tmp->next = stack->top;
	stack->top = tmp;
	stack->top->prev = NULL;
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
