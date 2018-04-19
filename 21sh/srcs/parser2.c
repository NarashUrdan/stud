/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:35:37 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/04/19 17:58:35 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

static void	ft_addleaf2(t_tree **tree, char *op, char **args)
{
	char	*cd;
	int		i;
	int		l;

	l = 0;
	while (args[l])
		l++;
	i = -1;
	cd = ft_strdup(args[0]);
	(*tree)->op = ft_strdup(op);
	if (!((*tree)->args = (char **)malloc(sizeof(char *) *(l + 1))))
		return ;
	(*tree)->args[l] = NULL;
	while (args[++i] != NULL)
		(*tree)->args[i] = ft_strdup(args[i]);
	(*tree)->cmd = ft_strdup(cd);
	free(op);
	ft_freedoublearray(args);
	free(cd);
	(*tree)->right = NULL;
	(*tree)->left = NULL;
}
static void	ft_sauceaupoivre(t_tree **tree, t_lex **cmd, int val)
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

void	ft_addleaf(t_tree **tree, t_lex **cmd, int val)
{
	t_lex	*tmp;
	char	**args;
	char	*op;
	int		i;
	t_tree	*left;

	i = 0;
	if (!(args = (char **)malloc(sizeof(char *) * 1)))
		return ;
	left = NULL;
	args[0] = NULL;
	op = ft_strnew(0);
	tmp = *cmd;
	while (tmp->value != val)
		tmp = tmp->next;
	while (tmp && (ft_strcmp(tmp->type, "sep") || !ft_strcmp(tmp->data, "`")))
	{
		if (!ft_strcmp(tmp->data, "`"))
		{
			op = ft_strjoinfree("BACK;", op, 2);
			ft_sauceaupoivre(&left, &tmp, tmp->value);
			tmp = tmp->next;
			while (tmp && ft_strcmp(tmp->type, "sep"))
				tmp = tmp->next;
		}
		if (ft_strcmp(tmp->type, "red") && ft_strcmp(tmp->type, "sep"))
		{
			args = ft_dbarr_add(args, tmp->data);
			i++;
		}
		else if (ft_strcmp(tmp->type, "sep"))
		{
			op = ft_strjoinfree(op, tmp->data, 1);
			op = ft_strjoinfree(op, ";", 1);
		}
		tmp = tmp->next;
	}
	ft_addleaf2(tree, op, args);
	if (left != NULL)
		(*tree)->left = left;
}

char	**ft_checkleaf(t_tree **tree, t_lex **cmd, int val)
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

/*static int	ft_sauceaupoivre(t_tree **tree, t_lex **cmd, int val)
{
	t_lex	*tmp;
	t_tree	*left;

	if (!(left = malloc(sizeof(t_tree))))
		return (1);
	tmp = *cmd;
	while (tmp->value != (val - 1))
		tmp = tmp->next;
	while (tmp->prev && ft_strcmp(tmp->type, "sep"))
		tmp = tmp->prev;
	ft_addleaf(&left, cmd, (tmp->value + 1));
	while (tmp->prev && tmp->value != (val - 1))
		tmp = tmp->prev;
	while (tmp->prev && ft_strcmp(tmp->type, "sep"))
		tmp = tmp->prev;
	ft_addleaf(tree, cmd, (tmp->value));
	(*tree)->args = ft_checkleaf(tree, cmd, val);
	(*tree)->op = ft_strjoinfree("BACK", (*tree)->op, 2);
	(*tree)->left = left;
	return (tmp->value - 1);
}
*/
static void	ft_addsep(t_tree **tree, t_lex **cmd, int val)
{
	t_lex	*tmp;
	t_tree	*right;
	t_tree	*nplug;

	if (!(nplug = malloc(sizeof(t_tree))) || !(right = malloc(sizeof(t_tree))))
		return ;
	tmp = *cmd;
	while (tmp->value != val)
		tmp = tmp->next;
	if (!ft_strcmp(tmp->data, "|"))
	{
		ft_addleaf(tree, cmd, val + 1);
		free(right);
		val -= 1;
	}
	else if (!ft_strcmp(tmp->type, "sep"))
	{
		(*tree)->cmd = ft_strdup(tmp->data);
		(*tree)->args = NULL;
		(*tree)->op = ft_strnew(0);
		ft_addleaf(&right, cmd, val + 1);
		(*tree)->args = NULL;
		(*tree)->right = right;
		val -= 1;
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
	*tree = NULL;
	return ;
}
