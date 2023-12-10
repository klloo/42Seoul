CC = cc
CFLAGS = -Werror -Wall -Wextra
SRCS = ft_display_file.c
OBJS = $(SRCS:.c=.o)
NAME = ft_display_file

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS)
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
