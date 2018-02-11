/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 05:06:28 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/11 07:47:50 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include "../libft/libft.h"
# include "get_next_line.h"
# include <sys/wait.h>

void	ft_other(char **tab, char **env);
void	ft_prompt(void);
char	**ft_env(char **tab, char **env);
char	**ft_envi(char **tab, char **env);
int		ft_echo(char **tab, char **env);
int		ft_cd(char **tab, char **env);
char	**merge(char **p1,char **p2, int s1, int s2);
int		ft_nbarg(char **tab);
void	ft_error(char *str);
void	ft_error2(char *str);
void	ft_unsetenv(char **tab, char **env, char *str);
#endif
