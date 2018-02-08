/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 05:06:28 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/08 03:58:59 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include "../libft/libft.h"
# include "get_next_line.h"

void	ft_prompt(void);

int		ft_echo(char **tab);

char	**ft_splitspaces(char *str);
int		ft_nbarg(char **tab);
void	ft_error(char *str);
#endif
