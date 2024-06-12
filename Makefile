# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmagere <bmagere@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 15:04:19 by bmagere           #+#    #+#              #
#    Updated: 2024/06/12 18:01:38 by bmagere          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT		= client
SERVER 		= server

HEADER 		= minitalk.h

CC 			= clang
SRC_SERVER	= 	server.c \
				ft_printf.c \
				ft_printf_utils.c \
				minitalk_utils.c
SRC_CLIENT	= 	client.c \
				ft_printf.c \
				ft_printf_utils.c \
				minitalk_utils.c

OBJ_SERVER 	= $(SRC_SERVER:%.c=%.o)
OBJ_CLIENT 	= $(SRC_CLIENT:%.c=%.o)

CFLAGS		= -Wall -Wextra -Werror -g

all:		$(SERVER) $(CLIENT) 

$(SERVER):	$(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $@
	@echo "\\033[1;35m|~~> Server built ! <~~|\\033[1;0m"

$(CLIENT):	$(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $@
	@echo "\\033[1;35m|~~> Client built ! <~~|\\033[1;0m"

clean:
	@rm -rf *.o
	@echo "\\033[5;35m|~~> Everything's cleaned ! <~~|\\033[1;0m"

fclean:		clean
	@rm -rf $(SERVER) $(CLIENT)

re:			fclean all

.PHONY:		all clean fclean re



