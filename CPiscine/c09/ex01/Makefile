CC = cc
CFLAGS = -Werror -Wall -Wextra
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = $(SRCS:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar -r $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I includes

clean:
	rm $(OBJS)

fclean:
	rm $(OBJS)
	rm $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
