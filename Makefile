# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 16:09:38 by dzboncak          #+#    #+#              #
#    Updated: 2019/02/26 18:05:04 by bkiehn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

LIB_DIR = ./libft

SRC = $(wildcard *.c)

$(NAME) : $(SRC)
	gcc -o$(NAME) $(SRC) -L$(LIB_DIR) -lft


debug : $(SRC)
	gcc -g3 $(SRC) -L$(LIB_DIR) -lft