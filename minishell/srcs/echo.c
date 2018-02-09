/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 02:13:35 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/09 04:10:59 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_echov(char *arg, char *str, char **env)
{
	int		i;
	int		l;
	char	*tmp;

	i = 0;
	l = ft_strlen(arg);
	while (env[i] && ft_strncmp(arg, env[i], l) != 0)
		i++;
	if (i >= ft_nbarg(env))
		str = ft_strjoinfree(str, " ", 1);
	else
	{
		tmp = ft_strsub(env[i], (l + 1), (ft_strlen(env[i]) - l));
		str = ft_strjoinfree(str, tmp, 3);
	}
	return (str);
}

int	ft_echo(char **tab, char **env)
{
	int		i;
	char	*str;

	i = 1;
	str = ft_strnew(0);
	while (tab[i])
	{
		if (ft_strncmp(tab[i], "$", 1) == 0)
			str = ft_echov((tab[i] + 1), str,  env);
		else
			str = ft_strjoinfree(str, tab[i], 1);
		str = ft_strjoinfree(str, " ", 1);
	   i++;	
	}
	ft_putendl(str);
	free(str);
	return (0);
}
