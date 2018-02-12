/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 02:38:05 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/12 07:24:01 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_cd2(char *pwd, char *opwd, char **tab, char **env)
{
	int		i;
	char	*tmpp;

	if (pwd == NULL)
	{
		ft_error2(tab[1]);
		return ;
	}
	tmpp = ft_strdup(pwd);
	i = 0;
	if (tab[1][ft_strlen(tab[1]) - 1] != '/')
		tab[1] = ft_strjoinfree(tab[1], "/", 1);
	pwd = ft_strjoinfree(pwd, "/", 1);
	pwd = ft_strjoinfree(pwd, tab[1], 1);
	if (chdir(pwd) == 0)
		ft_chpath(pwd, env, tmpp, tab[1]);
	else
	{
		opwd = ft_strjoinfree(opwd, "/", 1);
		opwd = ft_strjoinfree(opwd, tab[1], 1);
		if (chdir(opwd) == 0)
			ft_chpath(opwd, env, tmpp, tab[1]);
		else
			ft_error2(tab[1]);
	}
	free(tmpp);
	free(pwd);
}

void	ft_home(char **env, char *pwd)
{
	int		i;
	char	*home;

	i = 0;
	home = NULL;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "HOME=", 5) == 0)
			home = ft_strsub(env[i], 5, (ft_strlen(env[i]) - 5));
	}
	if (!home)
		ft_error("cd");
	else
	{
		chdir(home);
		home = ft_strjoinfree("PWD=", home, 2);
		pwd = ft_strjoinfree("OLDPWD=", pwd, 2);
		ft_replace(env, home, pwd);
	}
	if (home)
		free(home);
	free(pwd);
}

void	ft_old(char **tab,char *pwd, char **env)
{
	char	*old;
	int		i;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "OLDPWD=", 7) == 0)
			old = ft_strsub(env[i], 8, (ft_strlen(env[i]) - 8));
	}
	if (old == NULL)
		return ;
	old = ft_strjoinfree("/", old, 2);
	ft_chpath(old, env, pwd, tab[1]);
}

int		ft_checkcd(char *pwd, char **tab, char **env)
{
	if (pwd == NULL)
	{
		ft_error2(tab[1]);
		return (1);
	}
	else if (!tab[1])
	{
		ft_home(env, pwd);
		return (1);
	}
	else if (ft_strcmp(tab[1], "-") == 0)
	{
		ft_old(tab, pwd, env);
		return (1);
	}
	return (0);
}

char	*ft_kick(char **env)
{
	char	*pwd;
	int		i;

	i = 0;
	pwd = NULL;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PWD", 3) == 0)
			pwd = ft_strsub(env[i], 4, ft_strlen(env[i]));
	}
	return (pwd);
}

int		ft_cd(char **tab, char **env)
{
	int		i;
	char	*pwd;
	char	*opwd;

	i = 0;
	pwd = ft_kick(env);
	opwd = NULL;
	if (ft_checkcd(pwd, tab, env))
		return (0);
	else if (ft_strncmp(tab[1], "..", 2) == 0)
	{
		i = ft_strlen(pwd) - ft_strlen(ft_strrchr(pwd, '/'));
		opwd = ft_strsub(pwd, 0, i);
		if (ft_strcmp(tab[1], "..") != 0)
			opwd = ft_strjoinfree(opwd, (tab[1] + 2), 1);
		ft_chpath(opwd, env, pwd, tab[1]);
	}
	else
		ft_cd2(pwd, opwd, tab, env);
/*	if (pwd)
		free(pwd);
	if (opwd)
		free(opwd);*/
	return (0);
}
