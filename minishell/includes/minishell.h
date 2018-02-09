/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 05:06:28 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/09 07:19:08 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include "../libft/libft.h"
# include "get_next_line.h"

void	ft_prompt(char **env);
void	ft_env(char **tab, char **env);
int		ft_echo(char **tab, char **env);
int		ft_cd(char **tab, char **env);

char	**ft_splitspaces(char *str);
int		ft_nbarg(char **tab);
void	ft_error(char *str);
void	ft_error2(char *str);
#endif
