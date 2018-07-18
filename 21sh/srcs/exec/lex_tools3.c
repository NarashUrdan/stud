/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_tools3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <jukuntzm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:59:51 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/05/15 15:09:34 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		*ft_redirection3(char *str, t_tree *tree, int *fd)
{
	char	i;
	char	*tmp;

	i = str[0];
	if (ft_strncmp(str, "&>", 2))
	{
		fd[0] = -1;
		fd[0] = -1;
		ft_putendl_fd("21sh: Error syntax redirection", 2);
	}
	else
	{
		tmp = ft_strsub(str, 2, ft_strlen(str) - 2);
		tree->op = ft_strdup(tmp);
		tree->op = ft_strjoinfree(tree->op, ";", 1);
		str[0] = i;
		str = ft_strinsert(str, 62, ft_strichr(str, 62));
		tree->op = ft_strjoinfree(tree->op, str, 3);
		free(fd);
		fd = ft_redirection(tree);
		free(tmp);
	}
	return (fd);
}

void	ft_printtree(t_tree *tree)
{
	if (tree == NULL)
		return ;
	ft_printtree(tree->right);
	ft_printtree(tree->left);
	free(tree->cmd);
	free(tree->op);
	if (tree->args)
		tree->args = ft_dbarr_free(tree->args);
	free(tree);
}

int		ft_sarrint(int *tb)
{
	int		i;

	i = 0;
	while (tb[i] != -1)
		i++;
	return (i);
}

int		*ft_strjoindint(int *tb1, int *tb2)
{
	int		i;
	int		j;
	int		*tb;

	i = -1;
	j = 0;
	if (!(tb = (int *)malloc(sizeof(int) * (ft_sarrint(tb1)
		+ ft_sarrint(tb2) + 1))))
		return (tb);
	while (++i < ft_sarrint(tb1))
		tb[j++] = tb1[i];
	i = -1;
	while (++i < ft_sarrint(tb2))
		tb[j++] = tb2[i];
	tb[j] = -1;
	free(tb1);
	free(tb2);
	return (tb);
}

void	ft_freecmd(t_lex **cmd)
{
	while (*cmd)
	{
		free((*cmd)->type);
		free((*cmd)->data);
		if ((*cmd)->next)
			(*cmd) = (*cmd)->next;
		else
			break ;
		free((*cmd)->prev);
	}
	free(*cmd);
}
