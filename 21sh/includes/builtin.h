/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegros <slegros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:20:38 by slegros           #+#    #+#             */
/*   Updated: 2018/05/12 20:02:53 by slegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

typedef struct				s_cmd
{
	char					*cmd;
	char					*opt;
	char					**args;
}							t_cmd;

/*
** conversion.c
*/
void						ft_clean_cmd(t_cmd cmd);
t_cmd						ft_conversion_cd(char **entry);
t_cmd						ft_conversion(char **entry);

/*
** exec_history_1.c
*/
int							ft_exec_history(t_cmd cmd);

/*
** exec_history_2.c
*/
int							ft_history_d(char *arg);
int							ft_history_a(char **args, char opt);
int							ft_history_n(char **args);
int							ft_history_w(char **args, char opt);
int							ft_history_r(char **args);

/*
** exec_history_3.c
*/
int							ft_history_error(int mode, char *str, char c);
char						**ft_filecontent(void);

/*
** exec_exit.c
*/
int							ft_exec_exit(t_cmd cmd);

/*
** exec_echo.c
*/
int							ft_exec_echo(char **entry);

/*
** exec_env_1.c
*/
int							ft_prexec_env(t_cmd cmd, char **env);

/*
** exec_env_2.c
*/
int							ft_exec_env_args_2(char *tmp_line, char **tmp_env);
int							ft_exec_setenv(t_cmd cmd, char **env);
int							ft_exec_unsetenv(t_cmd cmd, char **env);

/*
** exec_env_error.c
*/
int							ft_env_error(char *str, int mode);

/*
** exec_cd_1.c
*/
int							ft_cd_error(int mode, char opt, char *str,
								char *tmp);
int							ft_exec_cd(t_cmd cmd);

/*
** exec_cd_2.c
*/
int							ft_cd_path(char *path, char opt, int mode);

#endif
