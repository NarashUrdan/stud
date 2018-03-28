/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:02:19 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/03/28 16:36:46 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

int		ft_sep(t_tree *tree, int i)
{
	if (tree == NULL)
		return (i);
	if (!ft_strcmp(tree->cmd, ";"))
	{
		i = ft_sep(tree->left, i);
		i = ft_sep(tree->right, i);
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
	//exit ?
	}
	else if (!tree->left && !tree->right)
		i = ft_exec(tree);
	else
	{
		i = ft_sep(tree->left, i);
		i = ft_sep(tree->right, i);
	}
	return (i);
}
