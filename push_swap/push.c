/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:30:38 by heeyjang          #+#    #+#             */
/*   Updated: 2023/10/11 15:14:36 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./push_swap.h"

void	push(t_stack *to, t_stack *from)
{
	t_node	*tmp;

	if (from->size < 1)
		return ;
	tmp = from->top;
	from->top = from->top->next;
	if (from->size > 1)
		from->top->prev = NULL;
	if (to->size == 0)
	{
		tmp->next = NULL;
		to->top = tmp;
		to->bottom = tmp;
	}
	else
	{
		tmp->next = to->top;
		to->top->prev = tmp;
		to->top = tmp;
	}
	to->size += 1;
	from->size -= 1;
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
