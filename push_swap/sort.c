/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:31:44 by heeyjang          #+#    #+#             */
/*   Updated: 2023/10/11 15:45:16 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./push_swap.h"

void	ft_sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bottom;

	top = a->top->content;
	mid = a->top->next->content;
	bottom = a->top->next->next->content;
	if (top > mid && mid > bottom && top > bottom)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && bottom > mid && top > bottom)
		ra(a);
	else if (mid > top && mid > bottom && bottom > top)
	{
		sa(a);
		ra(a);
	}
	else if (top > mid && bottom > mid && bottom > top)
		sa(a);
	else if (mid > top && mid > bottom && top > bottom)
		rra(a);
}

void	ft_sort_last(t_stack *stack)
{
	int	min_rotate;

	min_rotate = ft_get_rotate_target(stack, 0);
	while (min_rotate)
	{
		if (min_rotate > 0)
		{
			ra(stack);
			min_rotate--;
		}
		else
		{
			rra(stack);
			min_rotate++;
		}
	}
}

void	ft_sort_large(t_stack *a, t_stack *b)
{
	int	a_rotate;
	int	b_rotate;

	ft_sort_pivot(a, b);
	if (a->size == 2 || a->size == 3)
		ft_sort(a, b);
	while (b->size)
	{
		ft_set_min_rotate(a, b, &a_rotate, &b_rotate);
		ft_rotate_ab(a, b, &a_rotate, &b_rotate);
		ft_rotate_a(a, a_rotate);
		ft_rotate_b(b, b_rotate);
		pa(a, b);
	}
	ft_sort_last(a);
}

void	ft_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->top->content > a->top->next->content)
			sa(a);
	}
	else if (a->size == 3)
		ft_sort_three(a);
	else
		ft_sort_large(a, b);
}
