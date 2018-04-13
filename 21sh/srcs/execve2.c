/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:02:19 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/04/13 19:06:53 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

void	ft_res_fd(void)
{
	dup2(0, 0);
	dup2(1, 1);
	dup2(3, 3);
}

static int	ft_exec_pipe(t_tree *tree, int i)
{
	int	npfd[2];
	pid_t	pid;

	ft_putendl_fd("exec pipe", 2);
	if ((pipe(npfd) == -1) || ((pid = fork()) == -1))
		return (1);
	ft_putnbr_fd(pid, 2);
	if (pid == 0)
	{
		close(npfd[1]);
		dup2(npfd[0], 0);
		close(npfd[0]);
		ft_putendl_fd("fils", 2);
		i = ft_exec(tree);
//	waitpid(-1, &i, WEXITSTATUS(i));
		ft_res_fd();
	}
	else
	{
		close(npfd[0]);
		dup2(npfd[1], 1);
		close(npfd[1]);
		ft_putendl_fd("pere", 2);
		i = ft_sep(tree->left, i);
	//waitpid(-1, &i, WEXITSTATUS(i));
		ft_res_fd();
		return (i);
	}
	waitpid(-1, &i, WEXITSTATUS(i));
	ft_putendl_fd("tu arrive jusqu'ici ? ", 2);
	return (i);
}

int		ft_sep(t_tree *tree, int i)
{
	pid_t	pid;

	if (tree == NULL)
		return (i);
	if (!ft_strcmp(tree->cmd, ";"))
	{
				ft_putendl_fd(" rentre point virgule", 2);
		ft_putendl_fd(tree->cmd, 2);
		i = ft_sep(tree->left, i);
			ft_putstr_fd("right of ;", 2);
			i = ft_sep(tree->right, i);
		return (i);
	}
	else if (!ft_strcmp(tree->cmd, "&&"))
	{
		i = ft_sep(tree->left, i);
		if (i == 0)
			i = ft_sep(tree->right, i);
		else
			return (i);
	}
	else if (!ft_strcmp(tree->cmd, "||"))
	{
		i = ft_sep(tree->left, i);
		if (i > 0)
			i = ft_sep(tree->right, i);
		else
			return (i);
	}
	else if (!tree->left && !tree->right)
	{
		ft_putendl_fd(" rentre exec", 2);
		ft_putendl_fd(tree->cmd, 2);
	pid = fork();
		if (pid == 0)
			i = ft_exec(tree);
		waitpid (-1, &i, WEXITSTATUS(i));
	}
	else
		i = ft_exec_pipe(tree, i);
	return (i);
}
