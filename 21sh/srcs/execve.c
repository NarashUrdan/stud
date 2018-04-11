/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 09:55:59 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/04/11 18:24:09 by jukuntzm         ###   ########.fr       */
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

int		ft_exec(t_tree *tree, int pfd[])
{
	char		**arv;
	char		*path;
	pid_t		cpid;
	extern char **environ;
	int			i;

	i = 0;
	if (!tree)
		return (2);
	/* 	if (pipe(pfd) == -1)
		{
	*/	ft_putendl_fd("error pipe de merde", 2);
	/*	exit(EXIT_FAILURE);
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
	*/	
	close(pfd[0]);
	dup2(pfd[1], STDOUT_FILENO);
	close(pfd[1]);
	if ((path = ft_getpath(tree->cmd)) == NULL)
		return (-1);
	arv = ft_strsplit(tree->args, 59);
	cpid = fork();
	if (cpid == -1)
	{
		ft_putendl_fd("error fork", 2);
		exit (EXIT_FAILURE);
		// exit 6? (?)
	}
	else
	{
//	ft_putendl_fd(path, 2);
		i = execve(path, arv, environ);
//	ft_putnbr_fd(i, 2);
//	ft_putendl_fd("i size", 2);
	}
	close(pfd[1]);
//	ft_putendl_fd("cpid ", 2);
//	ft_putnbr_fd(cpid, 2);
//	write(2, "\n", 1);
	waitpid(cpid, &i, WEXITSTATUS(i));
		ft_putendl_fd("error pipe", 2);
	//	}
	return (i);
}
