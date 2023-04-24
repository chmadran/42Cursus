# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chmadran <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 12:18:34 by chmadran          #+#    #+#              #
#    Updated: 2023/04/24 13:34:31 by chmadran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=thread
RM = rm -f

#-----------SOURCES/OBJECTS--------------

SRC = sources/main.c sources/initdata.c sources/initmutex.c \
		sources/initphilo.c sources/routine.c sources/utils.c
OBJ = $(SRC:.c=.o)

#-----------COLORS-----------------------

BOLD_YELLOW	=	\033[1;33m

NO_COLOR	=	\033[0m

# ----------MESSAGES---------------------

EXEC_READY	=	echo "\n $(BOLD_YELLOW)Executable ready!\n"

CLEAN		=	echo "\n $(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"

FCLEAN		=	echo "\n $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executable\n"

#-----------RULES------------------------

all: $(NAME)

$(NAME): $(OBJ)
	@ $(CC) $(CFLAGS) $(OBJ) -o philo
	@ $(EXEC_READY)

clean:
	@ $(RM) $(OBJ)
	@ $(CLEAN)

fclean: clean
	@ $(RM) philo
	@ $(FCLEAN)

re: fclean $(NAME)
