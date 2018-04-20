/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:35:37 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/04/20 15:41:12 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

void		ft_sauceaupoivre(t_tree **tree, t_lex **cmd, int val)
{
	t_lex	*tmp;

	if (!((*tree = malloc(sizeof(t_tree)))))
		return ;
	tmp = *cmd;
	while (tmp->value != val + 1)
		tmp = tmp->next;
	while (ft_strcmp(tmp->type, "sep"))
		tmp = tmp->next;
	free(tmp->data);
	tmp->data = ft_strdup("|");
	while (tmp->value != val + 1)
		tmp = tmp->prev;
	ft_putendl_fd(tmp->data, 2);
	ft_addleaf(tree, &tmp, val + 1);
}

char		**ft_checkleaf(t_tree **tree, t_lex **cmd, int val)
{
	char	**tab;
	t_lex	*tmp;
	int		i;

	i = 0;
	tmp = *cmd;
	if (!(tab = (char **)malloc(sizeof(char *) * 2)))
		return (NULL);
	tab[1] = NULL;
	while (tmp->next && tmp->value != (val + 1))
		tmp = tmp->next;
	tab[0] = ft_strdup((*tree)->args[0]);
	while (tmp && ft_strcmp(tmp->type, "sep"))
	{
		tab = ft_dbarr_add(tab, tmp->data);
		tmp = tmp->next;
	}
	while ((*tree)->args[++i])
		tab = ft_dbarr_add(tab, (*tree)->args[i]);
	return (tab);
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
	{
		val = ft_addsep2(tree, cmd, val);
	}
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
