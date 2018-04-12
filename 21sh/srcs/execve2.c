/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:02:19 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/04/12 14:18:37 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

int		ft_newarg(t_tree *tree, int i, int pfd[])
{
	char	*tmp;
	int		l;

//	close(pfd[1]);
//	dup2(pfd[0], STDIN_FILENO);
	//	close(pfd[1]);
	//	tmp = NULL;
	ft_putendl_fd("c", 2);
	//	ft_putnbr_fd(pfd[0], 2);
	while ((l = get_next_line(pfd[0], &tmp)) > 0)
	{
		ft_putendl_fd("a", 2);
		ft_putendl_fd(tmp, 2);
		tree->args = ft_strjoinfree(tree->args, ";", 1);
		tree->args = ft_strjoinfree(tree->args, tmp, 3);
		//	tmp = NULL;
	}
//	close(pfd[0]);
		ft_putnbr_fd(l, 2);
	return (i);
}

void	ft_res_fd(void)
{
	dup2(0, STDIN_FILENO);
	dup2(1, STDOUT_FILENO);
}

static int	ft_exec_pipe(t_tree *tree, int i, int pfd[])
{
	int	npfd[2];
	char	*buf;
	pid_t	pid;

	(void)pfd;
	if ((pipe(npfd) == -1) || ((pid = fork()) == -1) || !(buf = (char *)malloc(sizeof(char) * 11)))
		return (1);
	if (pid == 0)
	{
		close(npfd[1]);
		dup2(npfd[0], STDIN_FILENO);
		close(npfd[0]);
		i = ft_sep(tree->left, i, npfd);
		ft_res_fd();
		return (i);
	}
	else
	{
		close(npfd[0]);
		dup2(npfd[1], STDOUT_FILENO);
		close(npfd[1]);
		i = ft_newarg(tree, i, npfd);
		i = ft_exec(tree, npfd);
		ft_res_fd();
	}
	waitpid(pid, &i, WEXITSTATUS(i));
	/*	ft_putendl_fd(tree->left->cmd, 2);
		i = ft_sep(tree->left, i, npfd);
		ft_putendl_fd("b", 2);
		i = ft_newarg(tree, i, npfd);
		if (pipe(pfd) == -1)
		return (1); 
		i = ft_exec(tree, npfd);
		ft_putendl_fd("sfs", 2);
		while (read(pfd[0], buf, 10) > 0)
		ft_putstr_fd(buf, 1);*/
	return (i);
}

int		ft_sep(t_tree *tree, int i, int pfd[])
{
	int	npfd[2];
	char *buf;
	buf = (char *)malloc(sizeof(char) * 11);
	buf[10] = '\0';
	if (tree == NULL)
		return (i);
	if (!ft_strcmp(tree->cmd, ";"))
	{
		//		ft_putendl_fd(" rentre point virgule", 2);
		i = ft_sep(tree->left, i, npfd);
		i = ft_sep(tree->right, i, npfd);
	}
	else if (!ft_strcmp(tree->cmd, "&&"))
	{
		//		ft_putendl_fd(" rentre double eper", 2);
		i = ft_sep(tree->left, i, npfd);
		if (i == 0)
			i = ft_sep(tree->right, i, npfd);
		else
			return (i);
	}
	else if (!ft_strcmp(tree->cmd, "||"))
	{
		//		ft_putendl_fd(" rentre double pipe", 2);
		i = ft_sep(tree->left, i, npfd);
		if (i > 0)
			i = ft_sep(tree->right, i, npfd);
		else
			return (i);
	}
	else if (!tree->left && !tree->right)
	{
		ft_putendl_fd(" rentre exec", 2);
		i = ft_exec(tree, pfd);
		ft_putendl_fd("d", 2);
		/*	while (read(pfd[0], buf, 10) > 0)
			ft_putstr_fd(buf, 1);*/
	}
	else
	{
		i = ft_exec_pipe(tree, i, npfd);
		/*		ft_putendl_fd(" rentre autre", 2);
				dup2(npfd[1], STDOUT_FILENO);
				i = ft_sep(tree->left, i, npfd);
				close(npfd[0]);
				dup2(npfd[1], STDIN_FILENO);
				i = ft_newarg(tree, i, npfd);
				i = ft_exec(tree, npfd);
				while (read(npfd[0], buf, 10) > 0)
				ft_putstr_fd(buf, 1);
				i = ft_sep(tree->right, i, npfd);
				if (tree->right)
				{
				i = ft_exec(tree, npfd);
				while (read(npfd[0], buf, 10) > 0)
				ft_putstr_fd(buf, 1);
				}*/
	}
	return (i);
}
