/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 05:01:29 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/11 09:55:09 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <sys/wait.h>
int	ft_pwd(char **env)
{
	char	*tmp;
	int		i;

	i = 0;
	while (env[i])
	{
		if ((tmp = ft_strnstr(env[i], "PWD=", 4)) != NULL)
		{
			ft_putendl(tmp + 4);
			break ;
		}
		i++;
	}
	if (i > ft_nbarg(env))
		exit (EXIT_FAILURE);
	return (0);
}

char	**ft_input(char **tab, char **env)
{
	if (tab[0] == NULL)
		return (env);
	if (ft_strcmp(tab[0], "pwd") == 0)
	{
		if (ft_nbarg(tab) != 1)
			ft_putendl_fd("pwd : too many arguments", 2);
		else
			ft_pwd(env);
	}
	else if (ft_strcmp(tab[0], "echo") == 0)
		ft_echo(tab, env);
	else if (ft_strcmp(tab[0], "cd") == 0)
		ft_cd(tab, env);
	else if (ft_strstr(tab[0], "env") != NULL)
		env = ft_env(tab, env);
	else
		ft_other(tab, env);
	return (env);
}

void	ft_prompt(void)
{
		write(1, "$> ", 3);
}

char **envir(char **env)
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

int	main(void)
{
	int 		ret;
	char		*line;
	extern char	**environ;
	char		**tab;

	environ = envir(environ);
	line = NULL;
	while (1)
	{
		ft_prompt();
		ret = get_next_line(0, &line);
		if (ret == -1)
		{
			ft_putendl_fd("error", 2);
			break ;
		}
		tab = ft_strsplit(line, ' ');
		free(line);
		if (tab[0] && ft_strcmp(tab[0], "exit") == 0)
			break ;
		else
			environ = ft_input(tab, environ);
		if (tab[0] != NULL)
			ft_freedoublearray(tab);
	}
		ft_freedoublearray(tab);
	ft_freedoublearray(environ);
	return (0);
}
