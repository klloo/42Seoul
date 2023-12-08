CC = cc
CFLAGS = -Werror -Wall -Wextra
SRCS = ft_printf.c ft_itoa.c ft_num_len.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I.

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS)
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
