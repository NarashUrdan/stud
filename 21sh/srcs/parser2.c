/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:35:37 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/03/21 15:41:29 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

void	ft_addleaf(t_tree **tree, t_lex **cmd, int val)
{
	t_lex 	*tmp;
	char	*args;
	char	*op;
	char	*cd;

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
	(*tree)->op = ft_strdup(op);
	(*tree)->args = ft_strdup(args);
	(*tree)->cmd = ft_strdup(cd);
	free(op);
	free(args);
	free(cd);
	(*tree)->right = NULL;
	(*tree)->left = NULL;
}

int		ft_sauceaupoivre(t_tree **tree, t_lex **cmd, int val)
{
	t_lex *tmp;
	t_tree *left;

	left = malloc(sizeof(t_tree));
	tmp = *cmd;
	while (tmp->value != (val - 1))
		tmp = tmp->next;
	/*ft_putendl_fd("--data--", 2);
	  ft_putendl_fd(tmp->data, 2);
	  */while (tmp->prev && ft_strcmp(tmp->type, "sep"))
	tmp = tmp->prev;
	/*ft_putendl_fd("--data->prev--", 2);
	  ft_putendl_fd(tmp->data, 2);
	  */ft_addleaf(&left, cmd, (tmp->value + 1));
	while (tmp->prev && tmp->value != (val - 1))
		tmp = tmp->prev;
	while (tmp->prev && ft_strcmp(tmp->type, "sep"))
		tmp = tmp->prev;
	ft_addleaf(tree, cmd, (tmp->value));
	(*tree)->left = left;
//	ft_putendl_fd((*tree)->cmd, 2);
	return (tmp->value - 1);
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
	if (!ft_strcmp(tmp->data, "|"))
	{
		ft_addleaf(tree, cmd, val + 1);
		free(right);
		val -= 1;
	}
	else if (!ft_strcmp(tmp->data, "`"))
	{
		val = ft_sauceaupoivre(tree, cmd, val);
//		(*tree) = right;
//		ft_putendl_fd((*tree)->cmd, 2);
		ft_putnbr_fd(val, 2);
		while ((*tree)->left)
			(*tree) = (*tree)->left;
	}
	else if (!ft_strcmp(tmp->type, "sep"))
	{
		(*tree)->cmd = ft_strdup(tmp->data);
		(*tree)->args = ft_strnew(0);
		(*tree)->op = ft_strnew(0);
		ft_addleaf(&right, cmd, val + 1);
		(*tree)->right = right;
		val -= 1;
	}
	while ((*cmd)->prev)
		(*cmd) = (*cmd)->prev;
	ft_makeabigtree(cmd, &nplug, val);
	(*tree)->left = nplug;
}

void	ft_makeabigtree(t_lex **cmd, t_tree **tree, int val)
{
	t_tree	*newplugged;
	t_lex	*tmp;

	tmp = *cmd;
	newplugged = *tree;
	if (val > 0)
	{
		while (tmp->value < val)
			tmp = tmp->next;
		while (tmp)
		{
			if (!ft_strcmp(tmp->type, "sep"))
			{
				ft_addsep(&newplugged, cmd, tmp->value);
//		ft_putendl_fd(newplugged->cmd, 2);
				return ;
			}
			if (tmp->value == 1)
			{
				ft_addleaf(&newplugged, cmd, 1);
//		ft_putendl_fd(newplugged->cmd, 2);
				return ;
			}
			tmp = tmp->prev;
		}
	}
	*tree = NULL;
//		ft_putendl_fd((*tree)->cmd, 2);
	return ;
}
