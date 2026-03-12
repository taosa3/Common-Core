NAME = megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror

SRCS = megaphone.cpp


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@rm -r $(NAME)

fclean: clean
	

re: fclean all

.PHONY: all clean fclean re