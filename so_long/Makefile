# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heeyjang <heeyjang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 16:36:49 by heeyjang          #+#    #+#              #
#    Updated: 2023/12/08 16:36:49 by heeyjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= so_long

CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror

SRCS 	=	./utils/ft_strjoin.c				\
			./utils/ft_itoa.c						\
			./utils/ft_get_map.c					\
			./utils/ft_movement.c 					\
			./utils/ft_split.c						\
			./utils/ft_put_image.c					\
			./utils/ft_put_text.c					\
			./get_next_line/get_next_line_utils.c	\
			./get_next_line/get_next_line.c			\
			./utils/ft_check_file_valid.c		    \
			./utils/ft_check_map_utils.c			\
			./utils/ft_check_map.c					\
			./utils/ft_animation.c					\
			./utils/ft_animation_utils.c			\
			./utils/ft_exit_door.c					\
			so_long.c

all: $(NAME)

OBJS	= $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	@$(CC) -L./mlx -lmlx -framework OpenGL -framework Appkit  $^ -o $@
%.o:%.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
