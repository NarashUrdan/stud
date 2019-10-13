# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jukuntzm <jukuntzm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 05:12:12 by jukuntzm          #+#    #+#              #
#    Updated: 2019/10/13 16:15:34 by jukuntzm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRC = megaphone.cpp

OBJ = megaphone.o

all: $(NAME)

%.o:%.c
	g++ -Wextra -Werror -Wall -o $@ -c $<

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
