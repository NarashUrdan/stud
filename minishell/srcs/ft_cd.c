/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 02:38:05 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/13 08:28:39 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_old(char *path, char **env)
{
	char	*oldpwd;
	int		i;

	i = -1;
	oldpwd = NULL;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "OLDPWD=", 7) == 0)
			oldpwd = ft_strsub(env[i], 7, (ft_strlen(env[i]) - 7));
	}
	if (oldpwd == NULL)
	{
		ft_errorcd("OLDPWD");
		return ;
	}
	chdir(oldpwd);
	ft_changepath(path, env);
	free(oldpwd);
}

void	ft_home(char *path, char **env)
{
	char	*home;
	int		i;

	i = -1;
	home = NULL;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "HOME=", 5) == 0)
			home = ft_strsub(env[i], 5, (ft_strlen(env[i]) - 5));
	}
	if (home == NULL)
	{
		ft_errorcd("HOME");
		return ;
	}
	chdir(home);
	ft_changepath(path, env);
	free(home);
}

void	ft_opath(char *tab, char *path, char **env)
{
	int		i;
	char	*pwd;

	i = 0;
	if (tab[0] == '/' && chdir(tab) == 0)
	{
		ft_changepath(path, env);
		return ;
	}
	pwd = getcwd(NULL, 0);
	pwd = ft_strjoinfree(pwd, "/", 1);
	pwd = ft_strjoinfree(pwd, tab, 1);
	if (chdir(pwd) == 0)
		ft_changepath(path, env);
	else
	{
		ft_error2(pwd);
		free(path);
	}
	free(pwd);
}

void	ft_tild(char *tab, char *path, char **env)
{
	char	*pwd;
	int		i;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "HOME=", 5) == 0)
			pwd = ft_strsub(env[i], 5, (ft_strlen(env[i]) - 5));
	}
	pwd = ft_strjoinfree(pwd, (tab + 1), 1);
	ft_putendl(pwd);
	if (chdir(pwd) == 0)
		ft_changepath(path, env);
	else
		ft_error2(pwd);
	free(pwd);
}

int		ft_cd(char **tab, char **env)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (ft_nbarg(tab) > 2)
	{
		ft_error("cd");
		free(path);
		return (0);
	}
	else if (!tab[1] || (ft_strcmp(tab[1], "~") == 0))
		ft_home(path, env);
	else if (ft_strcmp(tab[1], "-") == 0)
		ft_old(path, env);
	else if (ft_strncmp(tab[1], "~/", 2) == 0)
		ft_tild(tab[1], path, env);
	else
		ft_opath(tab[1], path, env);
	return (0);
}
