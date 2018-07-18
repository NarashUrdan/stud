/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <jukuntzm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:35:37 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/05/15 17:13:47 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			ft_check_sep(t_lex *tmp)
{
	if ((ft_strcmp(tmp->data, ";") && ft_strcmp(tmp->data, "||") &&
		ft_strcmp(tmp->data, "|") && ft_strcmp(tmp->data, "&&") &&
		ft_strcmp(tmp->data, "`")) || (tmp->next &&
		!ft_strcmp(tmp->next->type, "sep") && ft_strcmp(tmp->data, "`") &&
		ft_strcmp(tmp->next->data, "`")))
		return (1);
	return (0);
}

char		**ft_checkleaf(t_tree **tree, t_lex **cmd, int val)
{
	char	**taab;
	t_lex	*tmp;
	int		i;

	i = 0;
	tmp = *cmd;
	if (!(taab = (char **)malloc(sizeof(char *) * 2)))
		return (NULL);
	taab[1] = NULL;
	while (tmp->next && tmp->value != (val + 1))
		tmp = tmp->next;
	taab[0] = ft_strdup((*tree)->args[0]);
	while (tmp && ft_strcmp(tmp->type, "sep"))
	{
		taab = ft_dbarr_add(taab, tmp->data);
		tmp = tmp->next;
	}
	while ((*tree)->args[++i])
		taab = ft_dbarr_add(taab, (*tree)->args[i]);
	return (taab);
}

static int	ft_addsep2(t_tree **tree, t_lex **cmd, int val)
{
	t_tree	*right;
	t_lex	*tmp;

	tmp = *cmd;
	while (tmp->value != val)
		tmp = tmp->next;
	if (!(right = malloc(sizeof(t_tree))))
		return (-1);
	(*tree)->cmd = ft_strdup(tmp->data);
	(*tree)->args = NULL;
	(*tree)->op = ft_strnew(0);
	ft_addleaf(&right, cmd, val + 1);
	(*tree)->args = NULL;
	(*tree)->right = right;
	val -= 1;
	return (val);
}

static void	ft_addsep(t_tree **tree, t_lex **cmd, int val)
{
	t_lex	*tmp;
	t_tree	*nplug;

	if (!(nplug = malloc(sizeof(t_tree))))
		return ;
	tmp = *cmd;
	while (tmp->value != val)
		tmp = tmp->next;
	if (!ft_strcmp(tmp->data, "|"))
	{
		ft_addleaf(tree, cmd, val + 1);
		val -= 1;
	}
	else if (!ft_strcmp(tmp->type, "sep"))
		val = ft_addsep2(tree, cmd, val);
	while ((*cmd)->prev)
		(*cmd) = (*cmd)->prev;
	ft_makeabigtree(cmd, &nplug, val);
	(*tree)->left = nplug;
}

void		ft_makeabigtree(t_lex **cmd, t_tree **tree, int val)
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
			if (!ft_strcmp(tmp->type, "sep") && ft_strcmp(tmp->data, "`"))
			{
				ft_addsep(&newplugged, cmd, tmp->value);
				return ;
			}
			if (tmp->value == 1)
			{
				ft_addleaf(&newplugged, cmd, 1);
				return ;
			}
			tmp = tmp->prev;
		}
	}
	return ;
}
