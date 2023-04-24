# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chmadran <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 17:31:25 by chmadran          #+#    #+#              #
#    Updated: 2023/01/19 12:41:56 by chmadran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------Constantes------------------------

NAME = pushswap.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

#---------------Sources & Objects-----------------

SRC = sources/1.main.c sources/2.check_arg.c sources/3.init_stack.c \
	sources/4.ft_sort3.c sources/5.ft_sort.c sources/6.ft_pos_cost.c \
	sources/7.move_sort.c sources/8.move_rrotate.c sources/9.move_rotate.c \
	sources/10.move_swap.c sources/11.move_push.c \
	sources/free_stack.c sources/utils_gen.c sources/utils_stack.c \

OBJ = $(SRC:.c=.o)

#-----------------Colors------------------------

BOLD_YELLOW	=	\033[1;33m

NO_COLOR	=	\033[0m

# ----------------Messages -----------------------

EXEC_READY	=	echo "\n $(BOLD_YELLOW)Executable ready!\n"

CLEAN		=	echo "\n $(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"

FCLEAN		=	echo "\n $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executable\n"

#---------------Rules-----------------

all: $(NAME)

$(NAME): $(OBJ)
	@ $(CC) $(CFLAGS) $(OBJ) -o push_swap
	@ $(EXEC_READY)

clean:
	@ $(RM) $(OBJ)
	@ $(CLEAN)

fclean:
	@ $(RM) push_swap
	@ $(FCLEAN)

re : fclean $(NAME)

.PHONY: all clean fclean re
