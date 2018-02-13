/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 00:05:44 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/13 08:15:09 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_changepath(char *path, char **env)
{
	char	*pwd;
	int		i;

	i = -1;
	pwd = getcwd(NULL, 0);
	path = ft_strjoinfree("OLDPWD=", path, 2);
	pwd = ft_strjoinfree("PWD=", pwd, 2);
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PWD=", 4) == 0)
		{
			free(env[i]);
			env[i] = ft_strdup(pwd);
		}
		if (ft_strncmp(env[i], "OLDPWD=", 7) == 0)
		{
			free(env[i]);
			env[i] = ft_strdup(path);
		}
	}
	free(pwd);
	free(path);
}

int		ft_nbarg(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_errorcd(char *str)
{
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(" not set", 2);
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
