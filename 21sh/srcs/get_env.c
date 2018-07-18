/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegros <slegros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 18:02:19 by slegros           #+#    #+#             */
/*   Updated: 2018/04/22 18:48:49 by slegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char		**ft_setenv(void)
{
	char			*pwd;
	char			**env;
	struct passwd	*user;
	char			*tmp;

	if (!(env = (char **)malloc(sizeof(char *) * (5 + 1))))
		return (NULL);
	user = getpwuid(getuid());
	env[0] = ft_strjoin("USER=", user->pw_name);
	env[1] = ft_strjoin("HOME=", user->pw_dir);
	env[2] = ft_strjoin("SHELL=", user->pw_shell);
	pwd = ft_strdup("PWD=");
	tmp = getcwd(NULL, 0);
	pwd = ft_strjoinfree(pwd, tmp, 1);
	env[3] = ft_strdup(pwd);
	env[4] = ft_strdup("SHLVL=1");
	env[5] = ft_strdup("_=/usr/bin/env");
	env[6] = NULL;
	ft_strdel(&tmp);
	ft_strdel(&pwd);
	return (env);
}

char			**ft_get_env(void)
{
	extern char		**environ;
	char			**env;
	char			*shlvl;
	int				lvl;
	int				i;

	if (environ && environ[0] != NULL)
	{
		env = ft_dbarrdup(environ);
		if ((shlvl = ft_get_elem(env, "SHLVL")) != NULL)
		{
			lvl = ft_atoi(shlvl);
			lvl = (lvl <= 0) ? 1 : lvl + 1;
			i = ft_get_elemi(env, "SHLVL");
			free(shlvl);
			free(env[i]);
			env[i] = ft_itoa(lvl);
			env[i] = ft_strjoinfree("SHLVL=", env[i], 2);
		}
		else
			env = ft_dbarr_add(env, "SHLVL=1");
	}
	else
		env = ft_setenv();
	return (env);
}
