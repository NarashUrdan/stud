/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 07:04:32 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/11 08:09:44 by jukuntzm         ###   ########.fr       */
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

char	**ft_setenv(char **tab, char **env)
{
	int	i;
	char	**tmp;

	i = 0;

	if (ft_atoi(tab[3]) <= 0)
		return (env);
	while (env[i])
	{
		if (ft_strncmp(env[i], tab[1], ft_strlen(tab[1])) == 0)
		{
			free(env[i]);
			env[i] = ft_join(tab);
			return (env);
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
	return (tmp);
}

void	ft_unsetenv(char **tab, char **env, char *str)
{
	char	**tmp;
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (ft_nbarg(tab) > 2)
	{
		ft_putstr_fd(str, 2);
		ft_putendl_fd(" : too many arguments", 2);
		return ;
	}
	tmp = (char **)malloc(sizeof(char *) * (ft_nbarg(env)));
	tmp[ft_nbarg(env) - 1] = NULL;
	while (env[i])
	{
		if (ft_strncmp(tab[1], env[i], ft_strlen(tab[1])) == 0)
			i++;
		tmp[j] = ft_strdup(env[i]);
		free(env[i]);
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

char	**ft_env(char **tab, char **env)
{
	if (ft_strcmp(tab[0], "setenv") == 0)
		env = ft_setenv(tab, env);
	if (ft_strcmp(tab[0], "unsetenv") == 0)
		ft_unsetenv(tab, env, "unsetenv");
	if (ft_strcmp(tab[0], "env") == 0)
		env = ft_envi(tab, env);
	return (env);
}
