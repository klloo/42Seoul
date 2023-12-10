CC = gcc 
CFLAGS = -Wall -Wextra -Werror
INC = dict.h str_convert.h
OBJS = $(SRCS:.c=.o)
SRCS = convert.c get_input.c my_string.c print.c dictionary.c main.c set_dict.c init.c dict_string.c free.c
NAME = rush-02 

.PHONY: clean fclean re all

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

