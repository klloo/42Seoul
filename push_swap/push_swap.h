/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:48:17 by heeyjang          #+#    #+#             */
/*   Updated: 2023/10/11 15:16:08 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				content;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bottom;
}	t_stack;

void		ft_split_free(char **str);
int			ft_get_arr_len(int argc, char *argv[]);
int			ft_isspace(char c);
long long	ft_atoll(const char *str);
int			ft_check_integer(const char *str);
int			*ft_get_arr(int argc, char *argv[], int len);
t_node		*init_node(void);
t_stack		*init_stack(void);
void		free_stack(t_stack *stack);
void		ft_set_stack(t_stack *stack, int argc, char **argv);

void		ft_swap(int *a, int *b);
int			*ft_get_sorted_idx(int *arr, int *sorted_arr, int len);
int			*ft_sort_arr(int *arr, int *sorted_arr, int len, int *sorted);
int			*ft_get_idx_arr(int *arr, int len);

void		ft_divide_three_part(t_stack *a, t_stack *b, \
			int pivot1, int pivot2);
void		ft_sort_pivot(t_stack *a, t_stack *b);

void		push(t_stack *to, t_stack *from);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		reverse_rotate(t_stack *stack);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);
void		rotate(t_stack *stack);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		swap(t_stack *stack);
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);

void		ft_sort_three(t_stack *a);
void		ft_sort_large(t_stack *a, t_stack *b);
void		ft_sort(t_stack *a, t_stack *b);
void		ft_sort_three(t_stack *a);
void		ft_set_stack_min_max(t_stack *stack, int *min, int *max);
int			ft_get_rotate_target(t_stack *stack, int data);
int			get_get_correct_rotate(t_stack *stack, int data);
int			ft_get_rotate_cnt(t_stack *stack, int data);
int			ft_abs(int num);
void		ft_set_min_rotate(t_stack *a, t_stack *b, \
			int *a_rotate, int *b_rotate);
void		ft_rotate_ab(t_stack *a, t_stack *b, int *a_rotate, int *b_rotate);
void		ft_rotate_a(t_stack *a, int a_rotate);
void		ft_rotate_b(t_stack *b, int b_rotate);
void		ft_sort_last(t_stack *stack);
void		ft_sort_large(t_stack *a, t_stack *b);

void		print_error(int errno);

#endif
