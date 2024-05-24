# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momazouz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 14:30:55 by momazouz          #+#    #+#              #
#    Updated: 2024/04/06 13:11:57 by momazouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = \
	  ft_numbers.c ft_string.c ft_putcharactar_len.c ft_unsigned_int.c\
	  ft_hexadecimal.c ft_printf.c ft_atoi.c

OBJECTS = \
	  ft_numbers.o ft_string.o ft_putcharacter_len.o ft_unsigned_int.o\
	  ft_hexadecimal.o ft_printf.o ft_atoi.o

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
$(NAME): $(OBJECTS)
	ar -rc $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -rf $(NAME)

re: fclean all
