/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 00:08:11 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/08 05:30:14 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_quote(char *str)
{
	char	*tmp;
	
	while (1)
	{
		tmp = NULL;
		write (1, "quote> ", 8);
		get_next_line(0, &tmp);
		str = ft_strjoinfree(str, "/", 1);
		str = ft_strjoinfree(str, tmp, 1);
		if (strchr(tmp, 39) != NULL)
			break ;
		free(tmp);
	}
	free(tmp);
	return (str);
}

int	ft_echo(char **tab)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 1;
	str = ft_strnew(0);
	while (tab[i])
	{
		str = ft_strjoinfree(str, tab[i], 1);
		i++;
	}
	if ((tmp = strchr(str, 39)) != NULL)
	{
		if (strchr((tmp + 1), 39) == NULL)
			str = ft_quote(str);
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == 39)
		{
			while (str[++i] != 39)
			{
				if (str[i] == '/')
				{
					write(1, "\n", 1);
					i++;
				}
				write(1, &str[i], 1);
			}
		}
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
