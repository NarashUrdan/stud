/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 09:55:59 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/03/28 16:36:43 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

char	*ft_getpath(char *cmd)
{
	char	*path;
	char	**multipath;
	int		i;

	i = 0;
	if ((path = getenv("PATH")) == NULL)
	{
		ft_putendl_fd("error env", 2);
		exit(EXIT_FAILURE);
		// exit 4? (?)
	}
	multipath = ft_strsplit(path, ':');
	//	free(path);
	path = NULL;
	cmd = ft_strjoinfree("/", cmd, 2);
	while (multipath[i])
	{
		multipath[i] = ft_strjoinfree(multipath[i], cmd, 1);
		if ((access(multipath[i], X_OK)) == 0)
		{
			free(path);
			path = ft_strdup(multipath[i]);
			break ;
		}
		i++;
	}
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
	char		**arv;
	char		*path;
	pid_t		cpid;
	extern char **environ;
	int			i;

	i = 0;
/*	if (pipe(npfd) == -1)
	{
		ft_putendl_fd("error pipe de merde", 2);
		exit(EXIT_FAILURE);
		// exit 13 (141)
	}
	if (tree->left)
		i = ft_exec(tree->left, npfd);
	if (tree->right)
		i = ft_exec(tree->right, npfd);
	if (ft_issep(tree->cmd[0]))
		ft_sep(tree);
	else
	{
*/		if ((path = ft_getpath(tree->cmd)) == NULL)
			return (-1);
		arv = ft_strsplit(tree->args, 59);
		if ((cpid = fork()) == -1)
		{
			ft_putendl_fd("error fork", 2);
			exit (EXIT_FAILURE);
			// exit 6? (?)
		}
		else if (cpid == 0)
		{
			i = execve(path, arv, environ);
		}
		waitpid(cpid, &i, WEXITSTATUS(i));
//	}
	return (i);
}
