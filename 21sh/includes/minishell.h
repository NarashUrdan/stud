/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegros <slegros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:38:09 by slegros           #+#    #+#             */
/*   Updated: 2018/05/14 15:19:04 by slegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <pwd.h>
# include <grp.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <signal.h>
# include <time.h>
# include <sys/socket.h>
# include <sys/ioctl.h>
# include <netinet/in.h>
# include <net/if.h>
# include <arpa/inet.h>
# include <dirent.h>
# include <fcntl.h>
# include "line_edit.h"
# include "builtin.h"
# include "lexer.h"

typedef struct sockaddr_in	t_sockad;

/*
** mainc.c
*/
void						ft_launchshell(void);

/*
** sigleton.c
*/
char						*ft_path(int mode, char *path);
char						**ft_env(char **env, int mode);
int							ft_button_select(int mode, int val);
int							ft_exit_value(int mode, int val);
int							ft_button_line(int mode, int val);

/*
** get_env.c
*/
char						**ft_get_env(void);

/*
** bonus.c
*/
char						*ft_where(int mode, char *str);
void						ft_welcome(char **env);

/*
** tools_1.c
*/
int							is_reg(char *file);
int							ft_check_name(char *name);
char						**ft_change_pwd(char **env, char *new_pwd);
char						**ft_change_pwd_2(char **env, char *tmp_new);
pid_t						ft_pid(pid_t pid, int mode);

/*
** tools_2.c
*/
int							ft_get_iaccess(char **path, char *cmd);
char						*ft_get_elem(char **env, char *elem);
int							ft_get_elemi(char **env, char *elem);
char						*ft_get_entry(void);

/*
** tools_3.c
*/
t_wsize						ft_get_winsize(int mode);
char						**ft_mystrsplit(char *str, char c, int nb);
char						**ft_dbarr_dir(char *dir, char *file, int mode);
t_grl						ft_get_nb(char **ar_list, struct winsize w);
void						ft_print_space(int max_len, int len_elem);

/*
** term.c
*/
void						ft_term_check(char **env);
struct termios				ft_term(int mode);
void						ft_term_reset(void);

/*
** signal.c
*/
void						ft_signal(void);

#endif
