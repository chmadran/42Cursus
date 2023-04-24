# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chmadran <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 16:28:46 by chmadran          #+#    #+#              #
#    Updated: 2023/04/24 13:40:51 by chmadran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

MY_SOURCES = sources/ft_printf.c sources/ft_utils.c sources/ft_identify.c \
			sources/ft_print_p.c sources/ft_print_u.c \
			sources/ft_print_x_X.c sources/ft_print_d_i.c \

MY_OBJECTS = $(MY_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	ar -rcs $(NAME) $(MY_OBJECTS)

clean:
	$(RM) $(MY_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:		all clean fclean re
