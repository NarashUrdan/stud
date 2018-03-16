/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:35:37 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/03/16 16:55:50 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

void	ft_addleaf(t_tree **tree, t_lex **cmd, int val)
{
	t_lex 	*tmp;
	char	*args;
	char	*op;
	t_tree	*leaf;
	char	*cd;

	leaf = malloc(sizeof(t_tree));
	args = ft_strnew(0);
	op = ft_strnew(0);
	tmp = *cmd;
	while (tmp->value != val)
		tmp = tmp->next;
	cd = ft_strdup(tmp->data);
	tmp = tmp->next;
	while (tmp && ft_strcmp(tmp->type, "sep"))
	{
		if (ft_strcmp(tmp->type, "red"))
		{
			args = ft_strjoinfree(args, tmp->data, 1);
			args = ft_strjoinfree(args, ";", 1);
		}
		else
		{
			op = ft_strjoinfree(op, tmp->data, 1);
			op = ft_strjoinfree(op, ";", 1);
		}
		tmp= tmp->next;
	}
	leaf->op = (op[0] != '\0') ? ft_strdup(op) : NULL;
	leaf->args = (args[0] != '\0') ? ft_strdup(args) : NULL;
	leaf->cmd = ft_strdup(cd);
	/*	free(op);
	free(args);*/
	leaf->right = NULL;
	leaf->left = NULL;
	tree = &leaf;
}

void	ft_addsep(t_tree **tree, t_lex **cmd, int val)
{
	t_lex *tmp;
	t_tree *right;
	t_tree *nplug;

	nplug = malloc(sizeof(t_tree));
	right = malloc(sizeof(t_tree));
	tmp = *cmd;
	while (tmp->value != val)
		tmp =  tmp->next;
	if (!ft_strcmp(tmp->data, "|") || !ft_strcmp(tmp->data, "`"))
	{
		ft_addleaf(tree, cmd, val + 1);
		val -= 1;
	}
	else if (ft_strcmp(tmp->type, "sep"))
	{
		(*tree)->cmd = ft_strdup(tmp->data);
		(*tree)->args = NULL;
		(*tree)->op = NULL;
		ft_addleaf(&right, cmd, val + 1);
		(*tree)->right = right;
	}
	while ((*cmd)->prev)
		(*cmd) = (*cmd)->prev;
	ft_makeabigtree(cmd, &(*tree)->left, val);
/*	free(nplug);
	free(right);*/
}

void	ft_makeabigtree(t_lex **cmd, t_tree **tree, int val)
{
	t_tree	*newplugged;
	t_lex	*tmp;

	tmp = *cmd;
	newplugged = malloc(sizeof(t_tree));
	if (val < 1)
	{
		(*tree) = NULL;
		free(newplugged);
		return ;
	}
//	ft_putnbr_fd(val, 2);
	while (tmp->value < val)
		tmp = tmp->next;
	while (tmp)
	{
		if (!ft_strcmp(tmp->type, "sep"))
		{
	//			newplugged = *tree;
			ft_addsep(&newplugged, cmd, tmp->value);
				tree = &newplugged;
			return ;
		}
		if (tmp->value == 1)
		{
	//		newplugged = *tree;
			ft_addleaf(&newplugged, cmd, 1);
				tree = &newplugged;
			return ;
		}
		tmp = tmp->prev;
	}
	return ;
}
