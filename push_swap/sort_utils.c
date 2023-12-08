/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:31:38 by heeyjang          #+#    #+#             */
/*   Updated: 2023/10/11 15:46:45 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./push_swap.h"

void	ft_divide_three_part(t_stack *a, t_stack *b, int pivot1, int pivot2)
{
	if (a->top->content < pivot1)
	{
		pb(a, b);
		rb(b);
	}
	else if (a->top->content < pivot2)
		pb(a, b);
	else
		ra(a);
}

void	ft_sort_pivot(t_stack *a, t_stack *b)
{
	int	pivot1;
	int	pivot2;
	int	len;

	len = a->size;
	pivot1 = a->size / 3;
	pivot2 = a->size * 2 / 3;
	while (len--)
		ft_divide_three_part(a, b, pivot1, pivot2);
	while (a->size > 3)
		pb(a, b);
}

void	ft_set_stack_min_max(t_stack *stack, int *min, int *max)
{
	t_node	*cur;

	cur = stack->top;
	*min = cur->content;
	*max = cur->content;
	while (cur)
	{
		if (*min > cur->content)
			*min = cur->content;
		if (*max < cur->content)
			*max = cur->content;
		cur = cur->next;
	}
}
