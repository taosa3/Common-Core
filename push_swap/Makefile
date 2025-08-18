CC = cc
NAME = push_swap
SRCS = src/main.c \
	src/utils/check_winnable.c \
	src/utils/movement.c \
	src/utils/draw_game.c \
	src/utils/gameplay.c \
	src/utils/init_game.c \
	src/utils/map_utils.c \
	src/utils/read_map.c \
	src/utils/setup.c \
	src/utils/utils.c \
	src/utils/cleanup.c \
	$(GNL_DIR)/get_next_line.c \
	$(GNL_DIR)/get_next_line_utils.c

OBJ_DIR = Objects
OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)
LIBFT_DIR = includes/libft
PRINTF_DIR = includes/printf
GNL_DIR = includes/getnextline
MLX_DIR = minilibx-linux/
PRINTF = includes/printf/libftprintf.a
LIBFT = includes/libft/libft.a
MLXFLAGS = -Iminilibx-linux
MLX = minilibx-linux/libmlx.a -lXext -lX11 -lm -lz


CFLAGS = -Wall -Wextra -Werror -g -Iincludes/ -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR)
all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(PRINTF_DIR)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MLX) -o $(NAME)

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
