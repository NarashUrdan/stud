/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 22:11:19 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/11 07:48:46 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_envi(char **tab, char **env)
{
	if (!tab[1] && env != NULL)
	{
		ft_print_words_tables(env);
		return (env);
	}
	if (tab[1] && ft_strcmp(tab[1], "-i") == 0)
	{
		if (!tab[2])
		{
			ft_freedoublearray(env);
			env = NULL;
		}
	}
	if (tab[1] && env != NULL &&
		(ft_strcmp(tab[1], "-u") == 0 || ft_strcmp(tab[1], "--unset") == 0))
		ft_unsetenv((tab + 1), env, "env");
	return (env);
}
