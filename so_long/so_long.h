/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:36:33 by heeyjang          #+#    #+#             */
/*   Updated: 2023/12/08 16:36:39 by heeyjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "./get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_enemy {
	int		x_e;
	int		y_e;
	int		sign;
	int		x;
	int		path_to_move;
	int		sleep;
	int		sleep_for_move;
	char	*imgs[5];
}	t_enemy;

typedef struct s_vars {
	void			*mlx;
	void			*img;
	void			*win;
	int				win_w;
	int				win_h;
	int				x_p;
	int				y_p;
	int				movement;
	char			**map;
	int				collect;
	t_enemy			e_vars;
}	t_vars;

typedef struct s_map {
	int	c;
	int	p;
	int	e;
	int	x;
	int	y;
}	t_map;

char	**get_map(char *fmap);
void	to_left(t_vars **v);
void	to_right(t_vars **v);
void	to_up(t_vars **v);
void	to_down(t_vars **v);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	put_image(t_vars ***v, int x, int y, char *img);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
void	put_text(t_vars ***v);
void	put_image_to_map(char p, int x1, int y1, t_vars **v);
int		get_height(char **map);
void	check_map_valid(t_vars *vars);
void	check_file_valid(char *file_line);
void	check_elements(t_vars **vars);
void	ft_error(t_vars ***v, char *err);
int		animation(t_vars *vars);
int		get_position_for_enemy(t_vars **vars);
void	open_exit(t_vars **vars);
void	exit_door(t_vars ***v);

#endif
