# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chmadran <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 09:21:44 by chmadran          #+#    #+#              #
#    Updated: 2023/04/24 13:29:49 by chmadran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#----------------Sources & Objects--------------

CLIENT_SRC = sources/client.c sources/include.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

SERVER_SRC = sources/server.c sources/include.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)

CLIENT_SRC_BONUS = bonus/client_bonus.c bonus/include_bonus.c
CLIENT_OBJ_BONUS = $(CLIENT_SRC_BONUS:.c=.o)

SERVER_SRC_BONUS = bonus/server_bonus.c bonus/include_bonus.c
SERVER_OBJ_BONUS = $(SERVER_SRC_BONUS:.c=.o)

OBJ = $(CLIENT_OBJ) $(SERVER_OBJ)
OBJ_BONUS = $(CLIENT_OBJ_BONUS) $(SERVER_OBJ_BONUS)


#---------------Constantes---------------------

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

CLIENT = client
SERVER = server
NAME = makefile.a

#------------------Rules------------------------

all: $(NAME)

$(NAME) : client server

client : $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -o client

server : $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -o server

bonus : $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(CLIENT_OBJ_BONUS) -o client_bonus
	$(CC) $(CFLAGS) $(SERVER_OBJ_BONUS) -o server_bonus

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) client_bonus server_bonus

re: fclean $(NAME)

.PHONY: all client server bonus clean fclean re
