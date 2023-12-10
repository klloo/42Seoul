/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 22:28:17 by jooahn            #+#    #+#             */
/*   Updated: 2023/02/26 22:58:22 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

typedef struct s_dict {
	char	*value;
	char	*key;
	int		digit;
}			t_dict;

int		is_space(char c);
int		is_number(char c);
int		ft_strcmp(char *s1, char *s2);
void	init_dict_idx(int *i, int *idx);
int		is_space(char c);
int		get_len(char *str);
void	free_dict_arr(t_dict *dict);
int		is_number(char c);
int		get_numstr_len(char *str, int start);
char	*get_numstr(char *str, int i, int len);
int		get_cnt_line(char *str);
int		check_is_valid_dict(char *dict_str);
#endif
