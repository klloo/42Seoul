NAME = push_swap

LIBFT_DIR = ./libft/
LIBFT_NAME = libft.a
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

CC = cc
CFLAG = -Wall -Wextra -Werror

SRCS		= ./push_swap.c \
			./stack_utils.c \
			./parse_utils.c \
			./sort_array_utils.c \
			./push.c \
			./reverse_rotate.c \
			./rotate.c \
			./swap.c \
			./swap.c \
			./sort.c \
			./sort_utils.c \
			./rotate_stack.c \
			./rotate_stack_utils.c \

OBJS		= $(SRCS:%.c=%.o)

.c.o:
	$(CC) $(CFLAG) -c $< -o $@

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAG) $^ -o $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJS)

fclean:	
	make clean
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)
	
re :
	make fclean
	make all

.PHONY:	all clean fclean re
