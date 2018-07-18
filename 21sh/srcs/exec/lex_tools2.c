/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_tools2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegros <slegros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:14:11 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/05/06 16:52:59 by slegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			ft_isalphan(int c)
{
	if (ft_isop(c) && !ft_issep(c) && c != ' ' && c != 60 && c != 62)
		return (1);
	return (0);
}

int			ft_isred(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 60 || str[i] == 62)
			return (1);
		i++;
	}
	return (0);
}

int			ft_isop(int c)
{
	if (c == 34 || c == 39 || c == 96)
		return (0);
	return (1);
}

int			ft_issep(int c)
{
	if (c == 124 || c == 38 || c == 59)
		return (1);
	return (0);
}

char		*ft_type(int c)
{
	if (ft_isalphan(c))
		return ("char");
	else if (ft_isdigit(c))
		return ("int");
	else if (!ft_isop(c) || c == 32)
		return ("op");
	else if (ft_issep(c))
		return ("sep");
	else
		return (NULL);
}
