/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:31:34 by heeyjang          #+#    #+#             */
/*   Updated: 2023/10/11 15:14:34 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_get_rotate_target(t_stack *stack, int data)
{
	int			res;
	t_node		*cur;

	res = 0;
	cur = stack->top;
	while (cur)
	{
		if (cur->content == data)
			break ;
		res++;
		cur = cur->next;
	}
	if (res >= (stack->size + 1) / 2)
		res = (stack->size - res) * -1;
	return (res);
}

int	get_get_correct_rotate(t_stack *stack, int data)
{
	t_node		*cur;
	int			res;

	cur = stack->top;
	res = 1;
	while (cur->next)
	{
		if (data > cur->content && data < cur->next->content)
			break ;
		res++;
		cur = cur->next;
	}
	if (res >= (stack->size + 1) / 2)
		res = (stack->size - res) * -1;
	return (res);
}

int	ft_get_rotate_cnt(t_stack *stack, int data)
{	
	int	rotate_cnt;
	int	min;
	int	max;

	ft_set_stack_min_max(stack, &min, &max);
	if (data < min)
		rotate_cnt = ft_get_rotate_target(stack, min);
	else if (data > max)
		rotate_cnt = ft_get_rotate_target(stack, max) + 1;
	else
		rotate_cnt = get_get_correct_rotate(stack, data);
	return (rotate_cnt);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

void	ft_set_min_rotate(t_stack *a, t_stack *b, int *a_rotate, int *b_rotate)
{
	t_node	*cur;
	int		data;
	int		i;
	int		a_rotate_cnt;
	int		b_rotate_cnt;

	cur = b->top;
	i = -1;
	while (++i < b->size)
	{
		data = cur->content;
		a_rotate_cnt = ft_get_rotate_cnt(a, data);
		if (i >= (b->size + 1) / 2)
			b_rotate_cnt = (b->size - i) * -1;
		else
			b_rotate_cnt = i;
		if (i == 0 || \
		ft_abs(a_rotate_cnt) + ft_abs(b_rotate_cnt) < \
		ft_abs(*a_rotate) + ft_abs(*b_rotate))
		{
			*a_rotate = a_rotate_cnt;
			*b_rotate = b_rotate_cnt;
		}
		cur = cur->next;
	}
}
