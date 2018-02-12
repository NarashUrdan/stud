/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 00:05:44 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/12 07:28:14 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*path(char *ret, char *tab, char *opath)
{
	char *tmp;

	tmp = ft_strsub(ret, 0, (ft_strlen(ret) - 1));
	free(ret);
	ret = ft_strdup(tmp);
	free(tmp);
	if (ft_strcmp(ret, tab) == 0)
	{
		ret = ft_strjoinfree("/", ret, 2);
		ret = ft_strjoinfree(opath, ret, 2);
	}
	return (ret);
}

void	ft_chpath(char *ret, char **env, char *opath, char *tab)
{
	int i;

	i = -1;
	if (ret[ft_strlen(ret) - 1] == '/' || ft_strcmp(ret, tab) == 0)
		ret = path(ret, tab, opath);
	chdir(ret);
	ret = ft_strjoinfree("PWD=", ret, 2);
	opath = ft_strjoinfree("OLDPWD=", opath, 2);
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PWD", 3) == 0)
		{
			free(env[i]);
			env[i] = ft_strdup(ret);
		}
		if (ft_strncmp(env[i], "OLDPWD", 6) == 0)
		{
			free(env[i]);
			env[i] = ft_strdup(opath);
		}
	}
	free(ret);
	free(opath);
}

int		ft_nbarg(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_error2(char *str)
{
	ft_putstr_fd("cd: no such file or directory: ", 2);
	ft_putendl_fd(str, 2);
}

void	ft_error(char *str)
{
	char **tab;

	tab = ft_strsplit(str, ' ');
	ft_putstr_fd("minishell : command not found: ", 2);
	ft_putendl_fd(tab[0], 2);
	ft_freedoublearray(tab);
}
