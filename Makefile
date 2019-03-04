# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 16:09:38 by dzboncak          #+#    #+#              #
#    Updated: 2019/03/04 19:47:19 by dzboncak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

LIB_NAME = libftprintf.a

LIB_DIR = ./libft

SRC = $(wildcard *.c)

FLAGS = -Wall -Wextra -Werror

OBJ = $(wildcard *.o)

LIB_OBJ = libft/*.o

$(NAME) : $(SRC)
	gcc  -o$(NAME) $(SRC) -L$(LIB_DIR) -lft


debug : $(SRC)
	gcc -g3 $(SRC) -L$(LIB_DIR) -lft

liba :
	gcc -c $(SRC)
	rm main.o
	make -C $(LIB_DIR)
	ar rc $(LIB_NAME) $(OBJ) $(LIB_OBJ)