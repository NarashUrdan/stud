/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 09:55:59 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/04/19 13:30:03 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

char	*ft_path(char **multipath, char *tmp)
{
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	while (multipath[i])
	{
		multipath[i] = ft_strjoinfree(multipath[i], tmp, 1);
		if ((access(multipath[i], X_OK)) == 0)
		{
			path = ft_strdup(multipath[i]);
			break ;
		}
		i++;
	}
	return (path);
}

char	*ft_getpath(char *cmd)
{
	char	*path;
	char	*tmp;
	char	**multipath;

	if ((path = getenv("PATH")) == NULL)
	{
		ft_putendl_fd("error env", 2);
		exit(EXIT_FAILURE);
		// exit 4? (?)
	}
	multipath = ft_strsplit(path, ':');
	tmp = ft_strjoinfree("/", cmd, 0);
	path = ft_path(multipath, tmp);
	free(tmp);
	ft_freedoublearray(multipath);
	if (!path)
	{
		ft_putendl_fd("command not found: ", 2);
		ft_putendl_fd(cmd, 2);
	}
	return (path);
}

int		ft_exec(t_tree *tree)
{
//	char		**arv;
	char		*path;
	extern char **environ;
	int			i;
	pid_t		pid;

	pid = fork();
	i = 0;
	if (!tree)
		return (2);
	if ((path = ft_getpath(tree->cmd)) == NULL)
		return (-1);
//	ft_putendl("fsf");
//	arv = ft_strsplit(tree->args, 59);
	if (pid == 0)
	{
		i = execve(path, tree->args, environ);
		if (i == -1)
			ft_putendl_fd("error exec", 2);
	}
	free(path);
//	ft_freedoublearray(arv);
	waitpid(-1, &i, WEXITSTATUS(i));
	return (i);
}
