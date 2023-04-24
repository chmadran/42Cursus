# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chmadran <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 12:44:57 by chmadran          #+#    #+#              #
#    Updated: 2023/04/24 13:57:46 by chmadran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------Constantes-------

NAME = solong.a
CC = clang
CFLAGS = -Wall -Wextra -g3
MFLAGS = -lXext -lX11 -lm -lz

RM = rm -f
SRC = sources/1.main.c sources/2.ft_check_map.c sources/3.ft_init_map.c sources/3.ft_init_sprite.c \
		sources/4.ft_render_map.c sources/5.ft_move_player.c sources/6.ft_close_map.c \
		sources/ft_utils.c sources/7.ft_free_memory.c sources/2.ft_check_map_items.c
OBJ = $(SRC:.c=.o)


#--------Messages---------

YELLOW		= 	\033[1;33m

NO_COLOR	=	\033[0m

COMPILATION = echo "$(YELLOW)\nCompilation successful, the executable is ready.\n$(NO_COLOR)"

CLEAN = echo "$(YELLOW)\nThe object files have been deleted.\n$(NO_COLOR)"

FCLEAN = echo "$(YELLOW)\nThe executable has been deleted.\n$(NO_COLOR)"

#--------Rules------------

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux $(MFLAGS) ./libft/libft.a -o so_long
	@$(COMPILATION)

clean:
	@$(RM) $(OBJ)
	@$(MAKE) -C ./libft clean
	@$(CLEAN)

fclean: clean
	@$(RM) so_long
	@$(MAKE) -C ./libft fclean
	@$(FCLEAN)

re : fclean all

.PHONY : all clean fclean re
