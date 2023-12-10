CC = cc
CFLAGS = -Werror -Wall -Wextra
SRCS = do-op.c calculate.c operation.c
NAME = do-op

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f do-op.o calculate.o operation.o

fclean:
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all
