/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:31:51 by heeyjang          #+#    #+#             */
/*   Updated: 2023/10/11 15:14:31 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_stack	*init_stack(void)
{
	t_stack		*stack;

	stack = NULL;
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	return (stack);
}

t_node	*init_node(void)
{
	t_node		*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->content = 0;
	return (node);
}

void	free_stack(t_stack *stack)
{
	t_node	*next;
	t_node	*cur;

	cur = stack->top;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	free(stack);
}

void	ft_set_stack(t_stack *stack, int argc, char **argv)
{
	t_node	*new_node;
	int		i;
	int		len;
	int		*arr;
	int		*idx_arr;

	len = ft_get_arr_len(argc, argv);
	arr = ft_get_arr(argc, argv, len);
	idx_arr = ft_get_idx_arr(arr, len);
	i = -1;
	while (++i < len)
	{
		new_node = init_node();
		new_node->content = (int)idx_arr[i];
		if (stack->bottom)
		{
			stack->bottom->next = new_node;
			new_node->prev = stack->bottom;
		}
		stack->bottom = new_node;
		if (i == 0)
			stack->top = new_node;
		stack->size += 1;
	}
	free(idx_arr);
}
