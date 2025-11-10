CC = cc
NAME = minishell
SRCS = main.c \
	   

OBJ_DIR = Objects
OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)
LIBFT_DIR = printf/libft
LIBFT = printf/libft/libft.a

CFLAGS = -Wall -Wextra -Werror -g -I$(LIBFT_DIR) -
all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
