/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 01:58:56 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/04/10 15:05:20 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

char	*ft_joinarg(char *op, char *data)
{
	char	*str;

	if (op[0] != '\0')
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

void	ft_redisdead(char *str, char **args, char **op, char **cd)
{
	int	i;

	i = 1;
	*op = ft_strsub(str, 0, 1);
	ft_putendl_fd(str, 2);
	while (str[i] && !(str[i] == 60 || str[i] == 62))
		i++;
	ft_putnbr_fd(i, 2);
	if (i >= (int)ft_strlen(str))
	{
		*cd = NULL;
		*args = NULL;
		return ;
	}
	*cd = ft_strsub(str, 1, i - 1);
	*args = ft_strsub(str, i, (ft_strlen(str) - (i + 1)));
}

void	ft_addleaf(t_tree **tree, t_lex *cmd, int val)
{
	char	*args;
	char	*op;
	char	*cd;

	while (cmd && cmd->value != val)
		cmd = cmd->next;
	//ft_putendl_fd(cmd->next->type, 2);
	op = ft_strnew(0);
	args = ft_strnew(0);
	cd = ft_strnew(0);
//	ft_putnbr_fd(val, 2);
	while (cmd && ft_strcmp(cmd->type, "sep"))
	{
		if (!ft_strcmp(cmd->type, "red"))
		{
			ft_redisdead(cmd->data, &args, &op, &cd);
			break ;
		}
		if (!ft_strncmp(cmd->type, "op", 2))
		{
			ft_putendl_fd("a", 2);
			op = ft_joinarg(op, cmd->data);
		}
		if (!ft_strcmp(cmd->type, "arg"))
			args = ft_joinarg(args, cmd->data);
		cmd = cmd->next;
	}
//	ft_putendl_fd(op, 2);
	(*tree)->args = ft_strdup(args);
	(*tree)->op = ft_strdup(op);
	(*tree)->left = NULL;
	(*tree)->right = NULL;
	free(op);
	free(args);
	free(cd);
}

void	ft_addsep(t_tree **tree, t_lex *cmd, int val)
{
	t_tree	*leaf;
	t_tree	*left;
	t_lex	*tmp;

	tmp = cmd;
	left = malloc(sizeof(t_tree));
	leaf = malloc(sizeof(t_tree));
/*	while (cmd->value != val)
		cmd = cmd->next;
*/		ft_putendl_fd("---data--", 2);
		ft_putendl_fd(tmp->data, 2);
	if (ft_strcmp(cmd->data, "|") && ft_strcmp(cmd->data, "`"))
	{
		ft_addleaf(tree, cmd, val);
		(*tree)->cmd = ft_strdup(cmd->data);
		cmd = (cmd->next != NULL) ? cmd->next : cmd;
		if (cmd->next)
		{
			if (ft_strcmp(cmd->next->type, "co") == 0)
			{
			ft_addleaf(&leaf, cmd, val + 1);
			leaf->cmd = ft_strdup(cmd->data);
			(*tree)->right = leaf;
			}
			else
				(*tree)->right = NULL;
		}
	}
	else
	{
		cmd = cmd->next;
		(*tree)->cmd = ft_strdup(cmd->data);
//		ft_putendl_fd(tmp->data, 2);
//		ft_putnbr_fd(val, 2);
		ft_addleaf(tree, cmd, val + 1);
		//(*tree)->cmd = ft_strdup(cmd->data);
		(*tree)->args = ft_strjoinfree((*tree)->args, "[", 1);
		(*tree)->args = ft_strjoinfree((*tree)->args, "LEFT", 1);
		(*tree)->args = ft_strjoinfree((*tree)->args, "]", 1);
	}
	ft_makeabigtree(cmd, &left, (val - 1));
	(*tree)->left = left;
}

void	ft_makeabigtree(t_lex *cmd, t_tree **tree, int value)
{
	t_tree 	*newplugged;

	newplugged = malloc(sizeof(t_tree));
	if (value < 1)
	{
		(*tree) = NULL;
		free(newplugged);
		return ;
	}
	newplugged = *tree;
//	ft_putnbr(cmd->value);
//	ft_putnbr(value);
	while (cmd->value < value - 1)
		cmd = cmd->next;
	while (cmd->value > value)
		cmd = cmd->prev;
//	ft_putendl(cmd->data);
	while (cmd)
	{
		if (cmd->value == 1 || !ft_strcmp(cmd->type, "sep") || (!ft_strcmp(cmd->type, "red")))
		{
//	ft_putendl(cmd->data);
			ft_addsep(&newplugged, cmd, cmd->value);
			return ;
		}
		cmd = cmd->prev;
	}
	return ;
}
