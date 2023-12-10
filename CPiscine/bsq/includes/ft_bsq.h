/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:12:51 by seonmiki          #+#    #+#             */
/*   Updated: 2023/03/02 12:15:49 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_map_info {
	int		row_size;
	int		col_size;
	int		**int_map;
	char	empty_c;
	char	wall_c;
	char	full_c;
}	t_map_info;
int				ft_bsq(t_map_info map_info);
int				is_printable(char c);
int				is_in_charset(char target, char c1, char c2);
int				check_charset(char *map_str, int idx);
int				my_atoi(char *str, int end);
int				check_map_info(char *map_str);
int				**convert_map(char **map, char *char_set, int size, int c_size);
void			print_error(void);
void			print_map_error(void);
int				ft_most_small(int **print, int y, int x);
int				ft_find_bsq(int **print, int *dy, int *dx, t_map_info map_info);
int				get_char_start_idx(char *map_str);
char			*get_charset(char *map_str);
int				check_row_col(char *map_str, int size);
int				get_map_size(char *map_str);
int				get_first_col_len(char *map_str);
t_map_info		get_map_from_str(char *map_str);
char			*read_map(char *file_name);
t_map_info		get_map_info(char *file_name);
char			*my_strdup(char *src, int n);
char			**get_map(char *map_str, int i);
void			free_map(char **map);
unsigned int	ft_strlen(char *str);
char			*my_memcpy(char *dst, char *src, unsigned int n);
char			*my_realloc(char *ptr, unsigned int size);
t_map_info		get_map_info_std(void);
void			ft_print_findmap(t_map_info map_info, int dy, int dx, int max);
#endif
