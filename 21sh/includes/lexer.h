/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 07:32:18 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/04/13 16:11:31 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <sys/wait.h>
# include <sys/types.h> 
# define BUFF_SIZE 4096
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int get_next_line(const int fd, char **line);

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

void ft_printtree(t_tree *tree);
/*
** lexer.c
*/
int		ft_check(char *str);
void	ft_init(t_lex *cmd);

/*
** lex_tools.c
*/
void	ft_newred(char *str, t_lex **cmd, int *i);
int		ft_isalphan(int c);
int		ft_isnotspace(int c);
int		ft_isred(char *str);
int		ft_isop(int c);
int		ft_issep(int c);
void	ft_new(char *str, t_lex **cmd, int *i, int (ft_cmp(int c)));

/*
** parser.c
*/
void	ft_makeabigtree(t_lex **cmd, t_tree **tree, int value);

/*
** execve.c
*/
int	ft_exec(t_tree *tree);
/*
** execve2.c
*/
int ft_sep(t_tree *tree, int i);
#endif
