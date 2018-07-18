/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <jukuntzm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:20:34 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/05/15 17:13:36 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_redquote(char **red)
{
	int		i;
	char	*str;

	str = ft_strdup(*red);
	i = 0;
	while (i < (int)ft_strlen(str))
	{
		if (!ft_isop(str[i]))
			str = ft_strrem(str, ft_strichr(str, str[i]));
		i++;
	}
	free(*red);
	return (str);
}

void	ft_addleaf4(t_tree **tree)
{
	char	*tmp;

	if (!ft_strcmp((*tree)->cmd, "NONE"))
	{
		if (ft_strstr((*tree)->op, "<") && !ft_strstr((*tree)->op, "<<") &&
			((*tree)->op[0] != '<'))
		{
			free((*tree)->cmd);
			(*tree)->cmd = ft_strsub((*tree)->op, 0,
			ft_strichr((*tree)->op, '<'));
			tmp = ft_strdup(ft_strchr((*tree)->op, 60));
			(*tree)->op = ft_strdupf((*tree)->op, tmp);
			free((*tree)->args);
			(*tree)->args = (char **)malloc(sizeof(char *) * (2));
			(*tree)->args[0] = ft_strdup((*tree)->cmd);
			(*tree)->args[1] = NULL;
			free(tmp);
		}
	}
}

void	ft_addleaf3(t_tree **tree, char *op, char **args)
{
	char	*cd;
	int		i;
	int		l;

	l = 0;
	while (args[l])
		l++;
	i = -1;
	cd = (l == 0) ? ft_strdup("NONE") : ft_strdup(args[0]);
	(*tree)->op = ft_strdup(op);
	if (!((*tree)->args = (char **)malloc(sizeof(char *) * (l + 1))))
		return ;
	(*tree)->args[l] = NULL;
	while (args[++i] != NULL)
		(*tree)->args[i] = ft_strdup(args[i]);
	(*tree)->cmd = ft_strdup(cd);
	free(op);
	args = ft_dbarr_free(args);
	free(cd);
	(*tree)->right = NULL;
	(*tree)->left = NULL;
	ft_addleaf4(tree);
}

t_tree	*ft_addleaf2(char **op, char ***args, t_lex **tmp)
{
	t_tree	*left;

	left = NULL;
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
