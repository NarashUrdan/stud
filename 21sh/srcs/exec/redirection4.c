/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegros <slegros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 15:40:15 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/05/12 12:27:58 by slegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_check_tree(t_tree *tree, int i)
{
	t_tree	*tmp;
	char	*buf;
	char	**env;

	tmp = tree;
	while (tmp->left && !ft_issep(tmp->left->cmd[0]))
		tmp = tmp->left;
	if (tmp->left && ft_issep(tmp->left->cmd[0]) && ft_i(0, 0) != 1)
	{
		tmp = tmp->left;
		buf = ft_strdup(tmp->right->cmd);
		tmp->right->cmd = ft_strdupf(tmp->right->cmd, "NONE");
		ft_sep(tmp, i);
		ft_i(1, 1);
		tmp->right->cmd = ft_strdupf(tmp->right->cmd, buf);
		free(buf);
	}
	env = ft_env(NULL, 0);
	i = ft_exec_pipe(tree, i, env);
	return (i);
}

int	ft_i(int mode, int i)
{
	static int l;

	if (mode == 1)
		l = i;
	return (l);
}

int	*init_fd(char **red)
{
	int	*fd;
	int	i;

	i = 0;
	if (!(fd = (int *)malloc(sizeof(int) * (ft_dbarrlen(red) + 1))))
		return (NULL);
	while (i < ft_dbarrlen(red) + 1)
	{
		fd[i] = -1;
		i++;
	}
	return (fd);
}

int	ft_check_file(char *files)
{
	if (!ft_isdigit(files[0]) && access(files, F_OK) != 0)
	{
		ft_putendl_col_fd("21sh: Files doesn't exist", YEL, 2);
		return (-2);
	}
	if (access(files, F_OK | R_OK) == -1 && access(files, F_OK) == 0)
	{
		ft_putendl_fd("21sh: Permission denied", 2);
		return (-2);
	}
	return (0);
}

int	*ft_checkfd(int *fd)
{
	int	i;

	i = 0;
	while (fd[i] != -1)
	{
		if (fd[i] == -2)
		{
			fd[0] = -2;
			break ;
		}
		i++;
	}
	return (fd);
}
