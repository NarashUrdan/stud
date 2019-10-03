# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/19 10:07:08 by jukuntzm          #+#    #+#              #
#    Updated: 2019/09/19 10:09:54 by jukuntzm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_malloc
FLAG		=	-Werror -Wall -Wextra #-g3 -fsanitize=address 

PTH_LIBFT	=	libft/
LIBFT		=	$(PTH_LIBFT)libft.a
LNK_LIBFT	=	-L. $(LIBFT) -ltermcap

SRCS		=	srcs/ft_free.c \
				srcs/ft_malloc.c \
				srcs/ft_realloc.c \
				srcs/show_alloc_mem.c

OBJ 		=	$(SRCS:.c=.o)

INCLDS		=	-I $(PTH_LIBFT) -I includes/ft_malloc.h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	gcc $(FLAG) -o $@ $^ $(LNK_LIBFT)

$(LIBFT):
	make -C $(PTH_LIBFT)

%.o: %.c $(INCLDS)
	gcc $(FLAG) $(INCLDS) -c -o $@ $<

clean:
	rm -rf $(OBJ)
	make -C $(PTH_LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(PTH_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
