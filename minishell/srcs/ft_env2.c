/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 22:11:19 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/12 05:34:40 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_r(char **env)
{
	char	**tmp;

	tmp = (char **)malloc(sizeof(char *) * 4);
	tmp[0] = getcwd(NULL, 0);
	tmp[1] = ft_strdup("SHLVL=1");
	tmp[2] = ft_strdup("_=/usr/bin/env");
	tmp[3] = NULL;
	ft_freedoublearray(env);
	return (tmp);
}

char	**ft_envi(char **tab, char **env)
{
	int		i;
	char	**dup;

	dup = ft_arraycpy(env, ft_nbarg(env));
	i = 1;
	if (!tab[1] && env != NULL)
	{
		ft_print_words_tables(env);
		ft_freedoublearray(dup);
		return (env);
	}
	if (tab[1] && ft_strcmp(tab[1], "-i") == 0)
	{
		i = 2;
		dup = ft_r(dup);
	}
	if (tab[1] && env != NULL &&
		(ft_strcmp(tab[1], "-u") == 0 || ft_strcmp(tab[1], "--unset") == 0))
		ft_unsetenv((tab + 1), env, "env");
	ft_input((tab + i), dup);
	return (env);
}
