/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegros <slegros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:02:19 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/05/12 12:27:44 by slegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		ft_exec_pipe_norme(int *npfd, int i, int l)
{
	close(npfd[i]);
	dup2(npfd[l], l);
	close(npfd[l]);
}

int				ft_exec_pipe(t_tree *tree, int i, char **env)
{
	int	npfd[2];
	int	*fd;
	int	pid;

	if (pipe(npfd) == -1 || ((pid = fork()) == -1))
		return (1);
	if (pid == 0)
	{
		ft_exec_pipe_norme(npfd, 1, 0);
		fd = ft_redirection(tree);
		i = ft_exec(tree, env);
		restore_fds();
		exit(0);
	}
	else
	{
		ft_slip();
		ft_exec_pipe_norme(npfd, 0, 1);
		i = (ft_issep(tree->left->cmd[0])) ? ft_sep(tree->left->right, i) :
		ft_sep(tree->left, i);
		restore_fds();
	}
	wait(NULL);
	return (i);
}

char			**ft_new_args(t_tree *tree, int pfd[])
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

static int		ft_sep2(t_tree *tree, int i, char **env)
{
	int *fd;

	if (!ft_strcmp(tree->cmd, "||"))
	{
		i = ft_sep(tree->left, i);
		if (i > 0)
			i = ft_sep(tree->right, i);
		else
			return (i);
	}
	else if (!tree->left && !tree->right)
	{
		if (ft_strcmp(tree->cmd, "NONE"))
		{
			fd = ft_redirection(tree);
			if (fd[0] != -2)
				i = ft_check_builtin(tree, i, env);
			free(fd);
		}
	}
	else
		i = ft_check_tree(tree, i);
	return (i);
}

int				ft_sep(t_tree *tree, int i)
{
	char	**env;

	env = ft_env(NULL, 0);
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
		i = ft_sep2(tree, i, env);
	return (i);
}
