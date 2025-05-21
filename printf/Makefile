CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = ft_printf.c print_char.c print_num.c print_str.c print_unsigned.c print_ptr.c puthex_x.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f *.o ./a.out

fclean: clean
	rm -f $(NAME)

re: fclean all

compile: all
	cc $(CFLAGS) main.c $(NAME) libft/libft.a -Ilibft -o a.out

.PHONY: all clean fclean re