CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c pipex.c command_utils.c
OBJS = main.o pipex.o command_utils.o
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
NAME = pipex

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ${LIBFT}
	
$(LIBFT):
	make -C $(LIBFT_DIR) all

clean:
	make -C $(LIBFT_DIR) fclean
	rm -rf $(OBJS)

fclean:
	make clean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re