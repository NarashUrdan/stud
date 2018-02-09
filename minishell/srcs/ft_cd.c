/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 02:38:05 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/09 07:04:25 by jukuntzm         ###   ########.fr       */
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
			env[i] = ft_strdup(ret);
		if (ft_strncmp(env[i], "OLDPWD", 4) == 0)
			env[i] = ft_strdup(opath);
		i++;
	}
	free(opath);
	free(ret);
}

void	ft_cd2(char *pwd, char *opwd, char **tab, char **env)
{
	int		i;
	char	*tmpp;

	tmpp = ft_strdup(pwd);
	i = 0;
	if (tab[1][ft_strlen(tab[1]) - 1] != '/')
		tab[1] = ft_strjoinfree(tab[1], "/", 1);
	if (chdir(tab[1]) == 0)
		ft_chpath(tab[1], env, pwd, tab[1]);
	else
	{
		pwd = ft_strjoinfree(pwd, "/", 1);
		pwd = ft_strjoinfree(pwd, tab[1], 1);
		if (chdir(pwd) == 0)
			ft_chpath(pwd, env, tmpp, tab[1]);
		else
		{
			opwd = ft_strjoinfree(opwd, "/", 1);
			opwd = ft_strjoinfree(opwd, tab[i], 1);
			if (chdir(opwd) == 0)
				ft_chpath(opwd, env, tmpp, tab[1]);
			else
			ft_error2(tab[1]);
		}
	}
}

int	ft_cd(char **tab, char **env)
{
	int 	i;
	char	*pwd;
	char	*opwd;

	i = 1;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PWD", 3) == 0)
			pwd = ft_strsub(env[i], 4, ft_strlen(env[i]));
		if (ft_strncmp(env[i], "OLDPWD", 6) == 0)
			opwd = ft_strsub(env[i], 7, ft_strlen(env[i]));
		i++;
	}
	if (ft_strcmp(tab[1], "..") == 0)
	{
		i = ft_strlen(pwd) - ft_strlen(ft_strrchr(pwd, '/'));
			opwd = ft_strsub(pwd, 0 , i);
		ft_chpath(opwd, env, pwd, tab[1]);
	}
	else
		ft_cd2(pwd, opwd, tab, env);
	return (0);
}
