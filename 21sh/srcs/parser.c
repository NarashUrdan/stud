/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 01:58:56 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/03/12 16:30:14 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

char	*ft_joinarg(char *op, char *data)
{
	char	*str;

	if (op)
	{
		str = ft_strdup(op);
		free(op);
		str = ft_strjoinfree(str, ";", 1);
	}
	else
		str = ft_strnew(0);
	str = ft_strjoinfree(str, "['", 1);
	str = ft_strjoinfree(str, data, 1);
	str = ft_strjoinfree(str, "']", 1);
	return (str);
}

void	ft_addleaf(t_tree **tree, t_lex *cmd, int val)
{
	char	*args;
	char	*op;
	char	*cd;

	while (cmd->value != val + 1)
		cmd = cmd->next;
	op = ft_strnew(0);
	while (cmd && !ft_strcmp(cmd->type, "sep") && !ft_strcmp(cmd->type, "red"))
	{
		if (!ft_strcmp(cmd->type, "command"))
			cd = ft_strdup(cmd->data);
		else if (!ft_strcmp(cmd->type, "op"))
			op = ft_joinarg(op, cmd->data);
		else if (!ft_strcmp(cmd->type, "arg"))
			args = ft_joinarg(args, cmd->data);
		cmd->next;
	}
	(*tree)->cmd = ft_strdup(cd);
	(*tree)->args = ft_strdup(args);
	(*tree)->op = ft_strdup(op);
	(*tree)->left = NULL;
	(*tree)->right = NULL;
}

void	ft_addsep(t_tree **tree, t_lex *cmd, int val)
{
	while (cmd->value != val)
		cmd = cmd->next;
	if (ft_strcmp(cmd->data, "|") && ft_strcmp(cmd->data, "`"))
	{
		(*tree)->cmd = ft_strdup(cmd->data);
		ft_addleaf(tree->right, cmd, val);
	}
	else
	{
		ft_addleaf(tree, cmd, val);
		(*tree)->args = ft_strjoinfree((*tree)->args, "[", 1);
		(*tree)->args = ft_strjoinfree((*tree)->args, "LEFT", 1);
		(*tree)->args = ft_strjoinfree((*tree)->args, "]", 1);
	}
	ft_makeabigtree(cmd, tree->left, (value - 1);
}

t_tree	ft_makeabigtree(t_lex *cmd, t_tree **tree, int value)
{
	t_tree 	*newplugged;

	newplugged = malloc(sizeof(t_tree));
	if (value == 1)
	{
		free(newplugged);
		return (tree);
	}
	newplugged = *tree;
	while (cmd->value != value - 1)
		cmd = cmd->next;
	while (cmd)
	{
		if (!ft_strcmp(cmd->type, "sep") || (!ft_strcmp(cmd->type, "red")))
		{
			ft_addsep(&newplugged, cmd, cmd->value);
			return (newplugged);
		}
		cmd = cmd->prev;
	}
	return (tree);
}
