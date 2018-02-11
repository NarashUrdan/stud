/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 02:38:05 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/11 09:55:05 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_chpath(char *ret, char **env, char *opath, char *tab)
{
	int 	i;
	char	*tmp;

	i = 0;
	if (ret[ft_strlen(ret) - 1] == '/')
	{
		tmp = ft_strsub(ret, 0, (ft_strlen(ret) - 1));
		free(ret);
		ret = ft_strdup(tmp);
		free(tmp);
	}
	if (ft_strcmp(ret, tab) == 0)
	{
		ret = ft_strjoinfree("/", ret, 2);
		ret = ft_strjoinfree(opath, ret, 2);
	}
	ret = ft_strjoinfree("PWD=", ret, 2);
	opath = ft_strjoinfree("OLDPWD=", opath, 2);
	while (env[i])
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
		i++;
	}
	free(ret);
	free(opath);
}

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
}

void	ft_home(char **env, char *pwd)
{
	int		i;
	char	*home;

	i = 0;
	home = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "HOME=", 5) == 0)
			home = ft_strsub(env[i], 5,  (ft_strlen(env[i]) - 5));
		i++;
	}
	if (!home)
		ft_error("cd");
	else
	{
		i = 0;
		home = ft_strjoinfree("PWD=", home, 2);
		pwd = ft_strjoinfree("OLDPWD=", pwd, 2);
		while (env[i])
		{
			if (ft_strncmp(env[i], "PWD=", 4) == 0)
			{
				free(env[i]);
				env[i] = ft_strdup(home);
			}
			if (ft_strncmp(env[i], "OLDPWD=", 7) == 0)
			{
				free(env[i]);
				env[i] = ft_strdup(pwd);
			}
			i++;
		}
	}
}

int	ft_cd(char **tab, char **env)
{
	int 	i;
	char	*pwd;
	char	*opwd;

	i = 1;
	pwd = NULL;
	opwd = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PWD", 3) == 0)
			pwd = ft_strsub(env[i], 4, ft_strlen(env[i]));
		i++;
	}
	if (pwd == NULL)
		ft_error2(tab[1]);
	else if (!tab[1])
		ft_home(env, pwd);
	else if (ft_strncmp(tab[1], "..", 2) == 0)
	{
		i = ft_strlen(pwd) - ft_strlen(ft_strrchr(pwd, '/'));
		opwd = ft_strsub(pwd, 0 , i);
		if (ft_strcmp(tab[1], "..") != 0)
			opwd = ft_strjoinfree(opwd, (tab[1] + 2), 1);
		ft_chpath(opwd, env, pwd, tab[1]);
	}
	else
		ft_cd2(pwd, opwd, tab, env);
	return (0);
}
