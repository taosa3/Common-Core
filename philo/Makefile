NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=thread

SRCS = main.c \
		$(addprefix exec/, philo.c routines.c) \
		$(addprefix init/, init_helper.c init.c) \
		$(addprefix utils/, utils_helper.c utils.c)

OBJ_DIR = Objects
OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
