NAME = push_swap


CC = cc
CFLAGS = -Wall -Wextra -Werror
CFILES = \
	main.c \
	error.c \
	arg_check.c \


LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

OFILES = $(CFILES:.c=.o)


all: $(LIBFT) $(NAME)


$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OFILES)
	$(MAKE) -C $(MLX_DIR)
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

