NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

CFILES = \
	main.c \
	error.c \
	parse_args.c \
	push.c \
	swap.c \
	rotate.c \
	reverse_rotate.c \
	stack_utils.c \
	stack_init.c \
	sort_three.c \
	sort_algo.c \
	init_algo.c \
	cost_algo.c \
	move_algo.c

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

OFILES = $(CFILES:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re

