CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = bsq
SRCS = srcs/ft_bsq.c srcs/ft_check_map.c srcs/ft_convert_map.c srcs/ft_error.c srcs/ft_find_bsq.c\
 srcs/ft_get_charset.c srcs/ft_get_map_from_str.c srcs/ft_get_map.c srcs/ft_realloc.c srcs/map_parser.c\
 srcs/ft_print_map.c
OBJS = $(SRCS:.c=.o)

all = $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^ -I includes

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(NAME)

re :
	make fclean
	make