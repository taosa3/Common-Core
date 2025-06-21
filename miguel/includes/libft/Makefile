# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmiguel <anmiguel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 16:49:13 by anmiguel          #+#    #+#              #
#    Updated: 2025/03/08 15:31:59 by anmiguel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
# Source files
SOURCES = \
    ft_isalnum.c \
    ft_isalpha.c \
    ft_isascii.c \
    ft_isdigit.c \
    ft_isprint.c \
	ft_memset.c \
	ft_strlen.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memset.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_strrchr.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	
# Object files corresponding to the source files
OBJECTS = $(SOURCES:.c=.o)

# Bonus Source files
BONUS =	\
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c
	
# Object files corresponding to the bonus source files
BONUS_OBJECTS = $(BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
RM = rm -f

# Default target
all: $(NAME)

# Create the library
$(NAME): $(OBJECTS) $(BONUS_OBJECTS)
	$(AR) rcs $(NAME) $(OBJECTS) $(BONUS_OBJECTS)

# Rule to compile .c files to .o files
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

# Clean object files
clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)
	@touch bonus
	@rm bonus

# Clean and remove the library
fclean: clean
	$(RM) $(NAME)

# Rebuild everything
re: fclean all

bonus: $(OBJECTS) $(BONUS_OBJECTS)
			$(AR) rcs $(NAME) $(OBJECTS) $(BONUS_OBJECTS)
			@$(eval BONUS_FLAG=yes)
			@touch bonus

.PHONY: all clean fclean re
