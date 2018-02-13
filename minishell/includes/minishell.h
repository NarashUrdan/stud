/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 05:06:28 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/13 04:51:16 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include "../libft/libft.h"
# include "get_next_line.h"
# include <sys/wait.h>

void	ft_changepath(char *path, char **env);
void	ft_errorcd(char *str);
char	**ft_input(char **tab, char **env);
char	**ft_arraycpy(char **tab, int size);
void	ft_replace(char **env, char *home, char *pwd);
char	*ft_join(char **tab);
int		ft_pwd(char **env);
void	ft_other(char **tab, char **env);
void	ft_prompt(void);
char	**ft_env(char **tab, char **env);
char	**ft_envi(char **tab, char **env);
int		ft_echo(char **tab, char **env);
int		ft_cd(char **tab, char **env);
char	**merge(char **p1, char **p2, int s1, int s2);
int		ft_nbarg(char **tab);
void	ft_error(char *str);
void	ft_error2(char *str);
void	ft_unsetenv(char **tab, char **env, char *str);
#endif
