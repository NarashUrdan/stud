# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/14 22:19:39 by jukuntzm          #+#    #+#              #
#    Updated: 2018/02/27 09:55:23 by jukuntzm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_select

FLAG	=	-Werror -Wextra -Wall -g3 #-fsanitize=address 

PTH_LIBFT	=	libft
LIBFT		=	$(PTH_LIBFT)/libft.a
LNK_LIBFT	=	-L. $(LIBFT) -ltermcap

PTH_SRC		=	srcs

SRC			=	main.c\
				ft_print.c\
				input.c\
				move.c\
				ft_signal.c\
				ft_list.c\

SRCS		=	$(addprefix $(PTH_SRC), $(SRC))

OBJ			=	$(SRC:.c=.o)

PTH_INCLDS	=	includes
INCLDS		=	-I $(PTH_INCLDS) -I $(PTH_LIBFT) 
				
all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	gcc $(FLAG) -o $@ $^ $(LNK_LIBFT)

$(LIBFT):
	make -C $(PTH_LIBFT)

%.o: $(PTH_SRC)/%.c
	gcc $(FLAG) $(INCLDS) -c -o $@ $<

clean:
	rm -rf $(OBJ)
	make -C $(PTH_LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(PTH_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
