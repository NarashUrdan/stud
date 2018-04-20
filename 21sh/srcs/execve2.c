/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:02:19 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/04/20 15:40:32 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

void		ft_res_fd(void)
{
	dup2(0, 0);
	dup2(1, 1);
	dup2(3, 3);
}

static int	ft_exec_pipe(t_tree *tree, int i)
{
	int	npfd[2];

	if ((pipe(npfd) == -1))
		return (1);
	if (fork() == 0)
	{
		close(npfd[1]);
		dup2(npfd[0], 0);
		i = ft_exec(tree);
		ft_res_fd();
		exit(0);
	}
	if (fork() == 0)
	{
		close(npfd[0]);
		dup2(npfd[1], 1);
		i = ft_sep(tree->left, i);
		ft_res_fd();
		exit(0);
	}
	close(npfd[0]);
	close(npfd[1]);
	waitpid(-1, 0, 0);
	waitpid(-1, 0, 0);
	return (i);
}

char		**ft_new_args(t_tree *tree, int pfd[])
{
	char	*tmp;
	char	**tmp2;
	int		l;

	if (!(tmp2 = (char **)malloc(sizeof(char *) * 2)))
		return (NULL);
	tmp = ft_strnew(0);
	tmp[0] = '\0';
	tmp2[0] = ft_strdup(tree->args[0]);
	tmp2[1] = NULL;
	while ((l = get_next_line(pfd[0], &tmp)) > 0)
	{
		if (tmp[0] == '\0')
			break ;
		tmp2 = ft_dbarr_add(tmp2, tmp);
	}
	l = 0;
	while (tree->args[++l] != NULL)
		tmp2 = ft_dbarr_add(tmp2, tree->args[l]);
	return (tmp2);
}

static int	ft_sep2(t_tree *tree, int i)
{
	if (!ft_strcmp(tree->cmd, "||"))
	{
		i = ft_sep(tree->left, i);
		if (i > 0)
			i = ft_sep(tree->right, i);
		else
			return (i);
	}
	else if (!tree->left && !tree->right)
		i = ft_exec(tree);
	else if (!ft_strncmp(tree->op, "BACK", 4))
		i = ft_exec_bq(tree, i);
	else
		i = ft_exec_pipe(tree, i);
	return (i);
}

int			ft_sep(t_tree *tree, int i)
{
	if (tree == NULL)
		return (i);
	if (!ft_strcmp(tree->cmd, ";"))
	{
		i = ft_sep(tree->left, i);
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
	else
		ft_sep2(tree, i);
	return (i);
}
