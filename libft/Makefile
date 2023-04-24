# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chmadran <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 16:46:56 by chmadran          #+#    #+#              #
#    Updated: 2022/11/16 16:02:06 by chmadran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS += -Wall -Wextra -Werror
RM = rm -f

MY_SOURCES = ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c \
	ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
	ft_itoa.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcpy.c \
	ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c ft_split.c \
	ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strrchr.c \
	ft_toupper.c ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c  \
	ft_putstr_fd.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c \

MY_OBJECTS = $(MY_SOURCES:.c=.o)

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

BONUS_OBJECTS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	ar -rcs $(NAME) $(MY_OBJECTS)
so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(MY_SOURCES) $(BONUS)
	$(CC) -nostartfiles -shared -o libft.so $(MY_OBJECTS) $(BONUS_OBJECTS)

clean:
	$(RM) $(MY_OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME) 

bonus: $(MY_OBJECTS) $(BONUS_OBJECTS)
		ar rcs $(NAME) $(MY_OBJECTS) $(BONUS_OBJECTS)
