#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slegros <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/15 23:45:07 by slegros           #+#    #+#              #
#    Updated: 2018/05/12 15:31:39 by jukuntzm         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	21sh
FLAG		=	-Werror -Wall -Wextra

PTH_LIBFT	=	libft/
LIBFT		=	$(PTH_LIBFT)libft.a
LNK_LIBFT	=	-L. $(LIBFT) -ltermcap

SRCS		=	srcs/main.c \
				srcs/bonus.c \
				srcs/tools_1.c \
				srcs/tools_2.c \
				srcs/tools_3.c \
				srcs/sigleton.c \
				srcs/signal.c \
				srcs/term.c \
				srcs/get_env.c \
				srcs/builtin/exec_echo.c \
				srcs/builtin/exec_exit.c \
				srcs/builtin/exec_env_1.c \
				srcs/builtin/exec_env_2.c \
				srcs/builtin/exec_env_error.c \
				srcs/builtin/exec_cd_1.c \
				srcs/builtin/exec_cd_2.c \
				srcs/builtin/conversion.c \
				srcs/builtin/exec_history_1.c \
				srcs/builtin/exec_history_2.c \
				srcs/builtin/exec_history_3.c \
				srcs/line_edit/line_edit.c \
				srcs/line_edit/parse_checking.c \
				srcs/line_edit/history.c \
				srcs/line_edit/exclamation.c \
				srcs/line_edit/exclamation_2.c \
				srcs/line_edit/hist_move_1.c \
				srcs/line_edit/hist_move_2.c \
				srcs/line_edit/hist_jump.c \
				srcs/line_edit/hist_edit.c \
				srcs/line_edit/hist_eot_1.c \
				srcs/line_edit/hist_eot_2.c \
				srcs/line_edit/hist_tools_1.c \
				srcs/line_edit/hist_tools_2.c \
				srcs/line_edit/hist_tools_3.c \
				srcs/line_edit/hist_enter.c \
				srcs/line_edit/hist_tab.c \
				srcs/line_edit/hist_tab_search.c \
				srcs/line_edit/ft_select.c \
				srcs/line_edit/ft_select_tools.c \
				srcs/line_edit/ft_select_print.c \
				srcs/line_edit/ft_select_move.c \
				srcs/line_edit/ft_select_sel.c \
				srcs/line_edit/line_check_quotes.c \
				srcs/line_edit/line_check_op.c \
				srcs/line_edit/heredoc.c \
				srcs/exec/lexer.c\
				srcs/exec/lexer_2.c \
				srcs/exec/parser.c\
				srcs/exec/parser2.c\
				srcs/exec/lex_tools.c\
				srcs/exec/lex_tools2.c\
				srcs/exec/lex_tools3.c\
				srcs/exec/execve.c\
				srcs/exec/execve2.c\
				srcs/exec/execve3.c\
				srcs/exec/redirection.c\
				srcs/exec/redirection2.c\
				srcs/exec/redirection3.c\
				srcs/exec/redirection4.c\

OBJ 		=	$(SRCS:.c=.o)

INCLDS		=	-I $(PTH_LIBFT) -I includes/minishell.h
INCLDS_ALL	=	includes/builtin.h includes/lexer.h includes/line_edit.h \
				includes/minishell.h
all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	gcc $(FLAG) -o $@ $^ $(LNK_LIBFT)

$(LIBFT):
	make -C $(PTH_LIBFT)

%.o: %.c $(INCLDS_ALL)
	gcc $(FLAG) $(INCLDS) -c -o $@ $<

clean:
	rm -rf $(OBJ)
	make -C $(PTH_LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(PTH_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
