/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 07:32:18 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/04/20 16:01:05 by jukuntzm         ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int				get_next_line(const int fd, char **line);

typedef struct	s_lex
{
	int				value;
	char			*data;
	char			*type;
	struct s_lex	*next;
	struct s_lex	*prev;
}				t_lex;

typedef	struct	s_tree
{
	char			*cmd;
	char			**args;
	char			*op;
	struct s_tree	*left;
	struct s_tree	*right;
}				t_tree;

void			ft_printtree(t_tree *tree);
/*
** lexer.c
*/
int				ft_check(char *str);

/*
** lex_tools.c
*/
void			ft_checkdata(t_lex **cmd);
void			ft_newred(char *str, t_lex **cmd, int *i);
void			ft_new(char *str, t_lex **cmd, int *i, int (ft_cmp(int c)));

/*
** lex_tools2.c
*/
int				ft_isalphan(int c);
int				ft_isred(char *str);
int				ft_isop(int c);
int				ft_issep(int c);
char			*ft_type(int c);

/*
** parser.c
*/
void			ft_addleaf(t_tree **tree, t_lex **cmd, int val);
t_tree			*ft_addleaf2(char **op, char ***args, t_lex **tmp);
void			ft_addleaf3(t_tree **tree, char *op, char **args);

/*
** parser2.c
*/
void			ft_makeabigtree(t_lex **cmd, t_tree **tree, int value);
void			ft_sauceaupoivre(t_tree **tree, t_lex **cmd, int val);
char			**ft_checkleaf(t_tree **tree, t_lex **cmd, int val);

/*
** execve.c
*/
int				ft_exec(t_tree *tree);

/*
** execve2.c
*/
char			**ft_new_args(t_tree *tree, int pfd[]);
int				ft_sep(t_tree *tree, int i);
void			ft_res_fd(void);

/*
** execve3.c
*/
int				ft_exec_bq(t_tree *tree, int i);
int				ft_exec_left_bq(t_tree *tree, int i, int pfd[]);

#endif
