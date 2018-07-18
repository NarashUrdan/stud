/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <jukuntzm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 12:43:18 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/05/15 16:03:55 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef struct		s_fds
{
	int				fd_stdin;
	int				fd_stdout;
	int				fd_stderr;
}					t_fds;

typedef struct		s_lex
{
	int				value;
	char			*data;
	char			*type;
	struct s_lex	*next;
	struct s_lex	*prev;
}					t_lex;

typedef	struct		s_tree
{
	char			*cmd;
	char			**args;
	char			*op;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

/*
** lexer.c
*/
int					ft_check(char *str);
void				ft_checkcmd_norme(t_lex *tmp, int *l);

/*
** lexer_2.c
*/
t_lex				*ft_lex(char *str, int *l);

/*
** lex_tools.c
*/
void				ft_checkdata(t_lex **cmd);
void				ft_newred(char *str, t_lex **cmd, int *i);
void				ft_new(char *str, t_lex **cmd, int *i, int (ft_cmp(int c)));

/*
** lex_tools2.c
*/
int					ft_isalphan(int c);
int					ft_isred(char *str);
int					ft_isop(int c);
int					ft_issep(int c);
char				*ft_type(int c);

/*
** lex_tools3.c
*/
void				ft_freecmd(t_lex **cmd);
void				ft_printtree(t_tree *tree);
int					*ft_strjoindint(int *tb1, int *tb2);
int					*ft_redirection3(char *str, t_tree *tree, int *fd);

/*
** parser.c
*/
void				ft_addleaf(t_tree **tree, t_lex **cmd, int val);
t_tree				*ft_addleaf2(char **op, char ***args, t_lex **tmp);
void				ft_addleaf3(t_tree **tree, char *op, char **args);
char				*ft_redquote(char **red);

/*
** parser2.c
*/
void				ft_makeabigtree(t_lex **cmd, t_tree **tree, int value);
char				**ft_checkleaf(t_tree **tree, t_lex **cmd, int val);
int					ft_check_sep(t_lex *tmp);

/*
** execve.c
*/
int					ft_exec(t_tree *tree, char **env);

/*
** execve2.c
*/
char				**ft_new_args(t_tree *tree, int pfd[]);
int					ft_sep(t_tree *tree, int i);
int					ft_exec_pipe(t_tree *tree, int i, char **env);

/*
** execve3.c
*/
int					ft_check_builtin(t_tree *tree, int i, char **env);
int					ft_exec_bq(t_tree *tree, int i, char **env);
int					ft_exec_left_bq(t_tree *tree, int i, int pfd[]);

/*
** redirection.c
*/
int					*ft_redirection(t_tree *tree);
int					ft_red_right(char *str);
int					ft_red_left(char *str, int fd);

/*
** redirection2.c
*/
t_fds				*get_terminal(void);
void				restore_fds(void);
int					ft_red_agg(char *str);

/*
** redirection3.c
*/
int					ft_error_fd(char *files);
int					*ft_redirection2(char *str);
int					ft_check_redtmp(t_lex *tmp);

/*
** redirection4.c
*/
int					*init_fd(char **red);
int					ft_check_file(char *files);
int					*ft_checkfd(int *fd);
int					ft_check_tree(t_tree *tree, int i);
int					ft_i(int mode, int i);

#endif
