CC = cc
NAME = push_swap
SRCS = main.c \
	   moves.c \
	   moves_2.c \
	   index_sorted.c \
	   init_stack.c \
	   free_and_errors.c \
	   algorithm.c \
	   sort.c \
	   check_args.c

OBJ_DIR = Objects
OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)
LIBFT_DIR = printf/libft
PRINTF_DIR = printf
PRINTF = printf/libftprintf.a
LIBFT = printf/libft/libft.a

CFLAGS = -Wall -Wextra -Werror -g -I$(LIBFT_DIR) -I$(PRINTF_DIR)
all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(PRINTF_DIR)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)

fclean: clean
	rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
