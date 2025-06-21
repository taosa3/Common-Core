# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 16:49:13 by anmiguel          #+#    #+#              #
#    Updated: 2024/11/14 16:37:16 by anmiguel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
# Source files
SOURCES = 	ft_str.c \
			ft_num.c \
			ft_putptr.c \
			ft_printf.c \
	
# Object files corresponding to the source files
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
RM = rm -f

# Default target
all: $(NAME)

# Create the library
$(NAME): $(OBJECTS) 
	$(AR) rcs $(NAME) $(OBJECTS)

# Rule to compile .c files to .o files
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

# Clean object files
clean:
	$(RM) $(OBJECTS) 

# Clean and remove the library
fclean: clean
	$(RM) $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
