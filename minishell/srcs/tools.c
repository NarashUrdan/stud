/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 00:05:44 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/08 01:52:21 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_splitspaces(char *str)
{
	return (ft_strsplit(str, ' '));
}

int		ft_nbarg(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_error(char *str)
{
	char **tab;

	tab = ft_splitspaces(str);
	ft_putstr_fd("minishell : command not found: ", 2);
	ft_putendl_fd(tab[0], 2);
}
