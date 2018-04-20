/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:20:34 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/04/20 15:20:42 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

void	ft_addleaf3(t_tree **tree, char *op, char **args)
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
	if (!((*tree)->args = (char **)malloc(sizeof(char *) * (l + 1))))
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

t_tree	*ft_addleaf2(char **op, char ***args, t_lex **tmp)
{
	t_tree	*left;

	left = NULL;
	if (!ft_strcmp((*tmp)->data, "`"))
	{
		*op = ft_strjoinfree("BACK;", *op, 2);
		ft_sauceaupoivre(&left, tmp, (*tmp)->value);
		*tmp = (*tmp)->next;
		while ((*tmp) && ft_strcmp((*tmp)->type, "sep"))
			*tmp = (*tmp)->next;
	}
	if (ft_strcmp((*tmp)->type, "red") && ft_strcmp((*tmp)->type, "sep"))
		*args = ft_dbarr_add(*args, (*tmp)->data);
	else if (ft_strcmp((*tmp)->type, "sep"))
	{
		*op = ft_strjoinfree(*op, (*tmp)->data, 1);
		*op = ft_strjoinfree(*op, ";", 1);
	}
	return (left);
}

void	ft_addleaf(t_tree **tree, t_lex **cmd, int val)
{
	t_lex	*tmp;
	char	**args;
	char	*op;
	t_tree	*left;

	if (!(args = (char **)malloc(sizeof(char *) * 1)))
		return ;
	args[0] = NULL;
	op = ft_strnew(0);
	tmp = *cmd;
	while (tmp->value != val)
		tmp = tmp->next;
	while (tmp && (ft_strcmp(tmp->type, "sep") || !ft_strcmp(tmp->data, "`")))
	{
		left = ft_addleaf2(&op, &args, &tmp);
		tmp = tmp->next;
	}
	ft_addleaf3(tree, op, args);
	if (left != NULL)
		(*tree)->left = left;
}
