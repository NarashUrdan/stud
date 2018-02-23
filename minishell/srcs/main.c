/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 05:01:29 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/17 00:27:23 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <sys/wait.h>

void	ft_replace(char **env, char *home, char *pwd)
{
	int	i;

	i = -1;
	while (env[++i])
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
	}
}

char	**ft_input(char **tab, char **env)
{
	int	i;

	i = 0;
	if (tab[0] == NULL)
		return (env);
	else if (ft_strstr(tab[0], "env") != NULL &&
			(ft_strstr(tab[0], "/env") == NULL))
	{
		i = 1;
		env = ft_env(tab, env);
	}
	if (ft_strcmp(tab[0], "echo") == 0)
		ft_echo(tab, env);
	else if (ft_strcmp(tab[0], "cd") == 0)
		ft_cd(tab, env);
	else if (i == 0)
		ft_other(tab, env);
	return (env);
}

char	**envir(char **env)
{
	char	**tab;
	int		i;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_nbarg(env) + 1));
	tab[ft_nbarg(env)] = NULL;
	while (env[i])
	{
		tab[i] = ft_strdup(env[i]);
		i++;
	}
	return (tab);
}

char	**ft_lignes(void)
{
	int		ret;
	char	*line;
	char	**tab;

	line = NULL;
	ret = get_next_line(0, &line);
	if (ret == -1)
	{
		ft_putendl_fd("error", 2);
		exit(EXIT_FAILURE);
	}
	tab = ft_splitwhitespaces(line);
	if (line)
		free(line);
	return (tab);
}

int		main(void)
{
	extern char	**environ;
	char		**tab;

	environ = envir(environ);
	while (1)
	{
		write(1, "$> ", 3);
		tab = ft_lignes();
		if (tab[0] && ft_strcmp(tab[0], "exit") == 0)
			break ;
		else
			environ = ft_input(tab, environ);
		ft_freedoublearray(tab);
	}
	ft_freedoublearray(tab);
	ft_freedoublearray(environ);
	return (0);
}
