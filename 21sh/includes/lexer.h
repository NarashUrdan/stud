/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 07:32:18 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/03/12 16:10:08 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef struct	s_lex
{
	int				value;
	char			*data;
	char			*type;
	struct s_lex 	*next;
	struct s_lex	*prev;
}				t_lex;

typedef	struct	s_tree
{
	char			*cmd;
	char			*args;
	char			*op;
	struct	s_tree	*left;
	struct	s_tree	*right;
}				t_tree;

/*
** lexer.c
*/
int		ft_check(char *str);
void	ft_init(t_lex *cmd);

/*
** lex_tools.c
*/
int		ft_isalphan(int c);
int		ft_isred(int c);
int		ft_isop(int c);
int		ft_issep(int c);
void	ft_new(char *str, t_lex **cmd, int *i, int (ft_cmp(int c)));

/*
** parser.c
*/
#endif
