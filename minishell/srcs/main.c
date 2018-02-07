/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 05:01:29 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/07 05:26:22 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <sys/wait.h>
int	ft_input(char *str, char **env)
{
	char *tmp;
	int		i;

	i = 0;
	if (ft_strcmp(str, "pwd") == 0)
	{
		while (env[i])
		{
			if ((tmp = ft_strnstr(env[i], "PWD=", 4)) != NULL)
			{
				ft_putendl(tmp + 4);
				break ;
			}
			i++;
		}
	}
	else if (ft_strcmp(str, "echo") == 0)
	{
		ft_putendl(str + 5);
	}
	return (0);
}

void	ft_prompt(void)
{
	write (1, "$> ", 3);
}
int	main(int argc, char **argv)
{
	int 		ret;
	char		*line;
	extern char	**environ;
//	pid_t		cpid;

	argv = NULL;
	line = NULL;
	ft_print_words_tables(environ);
	while (argc)
	{
			ft_prompt();
			ret = get_next_line(0, &line);
		if (ft_strcmp(line, "exit") == 0)
			break ;
		else
			ft_input(line, environ);
	}
	return (0);
}
