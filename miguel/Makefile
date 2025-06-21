# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/22 14:17:02 by anmiguel          #+#    #+#              #
#    Updated: 2025/06/09 18:18:36 by anmiguel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------ EXECUTABLES ------------------
NAME = so_long

# ------------------ DIRECTORIES ------------------

SRC_DIR = src
INC_DIR = includes
OBJ_DIR = obj

LIBFT_DIR = $(INC_DIR)/libft
FT_PRINTFDIR = $(INC_DIR)/ft_printf
GNL_DIR = $(INC_DIR)/get_next_line
MLX_DIR = minilibx-linux

# ------------------ FILES ------------------

SRCS = 	$(SRC_DIR)/main/main.c \
		$(SRC_DIR)/utils/input.c \
		$(SRC_DIR)/map_utils/read_maps.c \
		$(SRC_DIR)/map_utils/flood_utils.c \
		$(SRC_DIR)/map_utils/utils_maps.c \
		$(SRC_DIR)/map_utils/duplicate_map.c \
		$(SRC_DIR)/map_utils/path_check.c \
		$(SRC_DIR)/so_long_utils/draw.c \
		$(SRC_DIR)/so_long_utils/cleanup.c \
		$(SRC_DIR)/so_long_utils/init.c \
		$(SRC_DIR)/so_long_utils/movement.c \
		$(SRC_DIR)/so_long_utils/gameplay.c \
		$(SRC_DIR)/so_long_utils/close.c \
		$(GNL_DIR)/get_next_line.c \
		$(GNL_DIR)/get_next_line_utils.c

# ------------------ OBJECTS ------------------

OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# ------------------ COMPILATION SETTINGS ------------------
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(INC_DIR) -I$(FT_PRINTFDIR) -I$(GNL_DIR)
MLXFLAGS = -I$(MLX_DIR)-lmlx -lXext -lX11 -lm -lz
RM = rm -f

# ------------------ LIBRARIES ------------------

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINT = $(FT_PRINTFDIR)/libftprintf.a
MLX = $(MLX_DIR)/libmlx.a

# ------------------ RULES ------------------
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINT) $(MLX)
	@$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(FT_PRINT) $(MLX)
	@echo "$(NAME) ready!"

# ------------------ OBJECTS BUILD ------------------

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

# ------------------ COMPILE RULES ------------------
$(OBJ_DIR)/%.o: src/%.c | $(CREATE_DIR)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

# ------------------ DIRECTORY CREATION ------------------
$(CREATE_DIR):
	@mkdir -p $(OBJ_DIR)/main
	@mkdir -p $(OBJ_DIR)/map_utils
	@mkdir -p $(OBJ_DIR)/so_long_utils
	@mkdir -p $(OBJ_DIR)/utils

# ------------------ LIBRARY COMPILATION ------------------
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(FT_PRINT):
	@$(MAKE) -C $(FT_PRINTFDIR) --no-print-directory

$(MLX):
	@$(MAKE) -C $(MLX_DIR) --no-print-directory

# ------------------ CLEAN RULES ------------------
clean:
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C $(FT_PRINTFDIR) clean --no-print-directory
	@$(MAKE) -C $(MLX_DIR) clean -no-print-directory
	@make -s clean -C ./minilibx-linux

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@$(MAKE) -C $(FT_PRINTFDIR) fclean --no-print-directory

re: fclean all

# ------------------ PHONY ------------------
.PHONY: all clean fclean re bonus
