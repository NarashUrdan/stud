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

char	**ft_arraycpy(char **tab, int size)
{
	char	**tmp;
	int	i;

	i = 0;
	tmp = (char **)malloc(sizeof(char *) * (size + 1));
	while (tab[i])
	{
		tmp[i] = ft_strdup(tab[i]);
		i++;
	}
	while (i <= size)
		tmp[i++] = NULL;
	return (tmp);
}

void	ft_setenv(char **tab, char **env)
{
	int	i;
	char	**tmp;

	i = 0;

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
	tmp = (char **)malloc(sizeof(char *) * (ft_nbarg(env) + 2));
	i = 0;	
	while (env[i])
	{
		tmp[i] = ft_strdup(env[i]);
		i++;
	}
	tmp[i] = ft_join(tab);
	tmp[i + 1] = NULL;
	ft_freedoublearray(env);
	i = 0;
//	ft_print_words_tables(tmp);
	write(1, "\n", 1);
	env = (char **)malloc(sizeof(char *) * (ft_nbarg(tmp) + 1));
	while (tmp[i])
	{
		env[i] = ft_strdup(tmp[i]);
		i++;
	}
	env[i] = NULL;
	ft_freedoublearray(tmp);
/*	tmp = ft_arraycpy(env, (ft_nbarg(env) + 1));
	tmp[ft_nbarg(env)] = ft_join(tab);
	tmp[ft_nbarg(env) + 1] = NULL;
	ft_freedoublearray(env);
	env = ft_arraycpy(tmp, ft_nbarg(tmp));
	ft_freedoublearray(tmp);
	ft_putnbr(ft_nbarg(tmp));
	ft_putnbr(ft_nbarg(env));*/
}

void	ft_unsetenv(char **tab, char **env)
{
	char	**tmp;
	int	i;
	int	j;

	j = 0;
	i = 0;
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
