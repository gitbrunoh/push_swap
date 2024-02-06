NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c split.c errors.c init_stack_a.c sort.c handle_nodes_a.c handle_nodes_b.c \
push_operation.c swap_operation.c rotate_operation.c reverse_operation.c utils.c utils2.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a

$(NAME): $(OBJ) $(LIBFT)
	$(CC) -g $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

all: $(NAME)

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re