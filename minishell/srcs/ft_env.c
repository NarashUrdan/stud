/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 07:04:32 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/09 09:01:50 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_join(char **tab)
{
	char	*str;

	str = ft_strjoinfree(tab[1], "=", 0);
	str = ft_strjoinfree(str, tab[2], 1);
	return (str);
}

void	ft_setenv(char **tab, char **env)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	if (ft_atoi(tab[3]) <= 0)
		return ;
	while (env[i])
	{
		if (ft_strncmp(env[i], tab[1], ft_strlen(tab[1])) == 0)
		{
			free(env[i]);
			env[i] = ft_join(tab);
			return ;
		}
		i++;
	}
	tmp = (char **)malloc(sizeof(char *) * 2);
	tmp[0] = ft_join(tab);
	tmp[1] = NULL;
	env = merge(env, tmp, ft_nbarg(env), 1);
	ft_putnbr(ft_nbarg(env));
	ft_print_words_tables(env);
}

void	ft_unsetenv(char **tab, char **env)
{
	char	**tmp;
	int		j;
	int		i;

	i = 0;
	j = 0;
	if (ft_nbarg(tab) > 2)
	{
		ft_putendl_fd("unsetenv : too many arguments", 2);
		return ;
	}
	tmp = (char **)malloc(sizeof(char *) * (ft_nbarg(env)));
	tmp[ft_nbarg(env) - 1] = NULL;
	while (env[i])
	{
		if (ft_strncmp(tab[1], env[i], ft_strlen(tab[1])) == 0)
			i++;
		tmp[j] = ft_strdup(env[i]);
		i++;
		j++;
	}
	i = 0;
	while (tmp[i])
	{
		free(env[i]);
		env[i] = ft_strdup(tmp[i]);
		i++;
	}
	env[i] = NULL;
	ft_freedoublearray(tmp);
}

void	ft_env(char **tab, char **env)
{
	if (ft_strcmp(tab[0], "setenv") == 0)
		ft_setenv(tab, env);
	if (ft_strcmp(tab[0], "unsetenv") == 0)
		ft_unsetenv(tab, env);
/*	if (ft_strcmp(tab[0], "env") == 0)
		ft_en(tab, env);
*/}
