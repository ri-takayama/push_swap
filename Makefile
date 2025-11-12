NAME = push_swap
SRCS = \
	./src/ft_sort.c \
	./src/count_operation.c \
	./src/ft_utils1.c \
	./src/ft_utils2.c \
	./src/ft_utils3.c \
	./src/ft_sort_three.c \
	./src/ft_free.c \
	./src/check_args_utils.c \
	./src/operations_push_swap.c \
	./src/handle_args.c \
	./src/get_best_operation.c \
	./src/is_sorted.c \
	./src/operations_rotate.c \
	./src/push_swap.c \
	./src/print_error.c \
	./src/run_operations_pb.c \
	./src/run_operations_pa.c

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDE = -I$(LIBFT_DIR)

OBJS = $(SRCS:.c=.o)
INCLUDE = -I./include
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) $(LIBFT_INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS)
	make fclean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re