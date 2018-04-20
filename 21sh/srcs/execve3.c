/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:26:38 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/04/20 15:38:43 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

int	ft_exec_left_bq(t_tree *tree, int i, int pfd[])
{
	close(pfd[0]);
	dup2(pfd[1], 1);
	i = ft_sep(tree->left, i);
	write(1, "\n", 1);
	close(pfd[1]);
	ft_res_fd();
	return (i);
}

int	ft_exec_bq(t_tree *tree, int i)
{
	int		pfd[2];

	if ((pipe(pfd) == -1))
		return (1);
	if (fork() == 0)
	{
		i = ft_exec_left_bq(tree, i, pfd);
		exit(i);
	}
	if (fork() == 0)
	{
		close(pfd[1]);
		dup2(pfd[0], 0);
		tree->args = ft_new_args(tree, pfd);
		i = ft_exec(tree);
		ft_res_fd();
		exit(i);
	}
	wait(NULL);
	wait(NULL);
	return (i);
}
