/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 05:01:29 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/08 05:30:11 by jukuntzm         ###   ########.fr       */
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

int	ft_input(char **tab, char **env)
{

	if (ft_strcmp(tab[0], "pwd") == 0)
	{
		if (ft_nbarg(tab) != 1)
			ft_putendl_fd("pwd : too many arguments", 2);
		else
			ft_pwd(env);
	}
	else if (ft_strcmp(tab[0], "echo") == 0)
		ft_echo(tab);
	else
		ft_error(tab[0]);
//	else if (ft_strncmp(str, "echo", 4) == 0)
//		ft_echo(line, en);
	return (0);
}

void	ft_prompt(void)
{
	write (1, "$> ", 3);
}
int	main(void)
{
	int 		ret;
	char		*line;
	extern char	**environ;
	char		**tab;

	line = NULL;
	ft_print_words_tables(environ);
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
		if (ft_strcmp(tab[0], "exit") == 0)
			break ;
		else
			ft_input(tab, environ);
	}
	ft_freedoublearray(tab);
	return (0);
}
