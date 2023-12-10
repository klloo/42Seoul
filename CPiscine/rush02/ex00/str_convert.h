/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_convert.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:57:38 by heeyjang          #+#    #+#             */
/*   Updated: 2023/02/26 23:38:18 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_CONVERT_H
# define STR_CONVERT_H

# include "dict.h"

int		is_num(char c);
int		is_space(char c);
int		get_num_len(char *str);
char	*int_to_string(int num);
int		get_len(char *str);
int		print_dict_error(void);
int		print_error(void);
char	*get_input(char *str);
t_dict	*set_dict(char *file_name);
int		just_zero(t_dict *dict_arr);
int		convert(char *str, t_dict *dict_arr);
void	print_str(char *str);
void	print_str_spc(char *str);
void	free_dict_arr(t_dict *dict);
char	*charcat(char c1, char c2);
char	*get_value(char *key, t_dict *dict_arr);
char	*get_value_digit(int digit, t_dict *dict_arr);
void	init(int *idx, int *len, int *remain_num, char *str);
int		hundred(char num, int digit, t_dict *dict_arr, int *remain_num);
int		ten(char *num, int digit, t_dict *dict_arr, int *remain_num);
int		one(char num, int digit, t_dict *dict_arr, int *remain_num);
void	init_get_input(int *i, int *result_idx);
#endif