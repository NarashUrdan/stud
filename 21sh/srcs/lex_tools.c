/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 08:06:01 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/03/07 00:38:29 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

int			ft_isalphan(int c)
{
	if (!ft_isred(c) && !ft_isdigit(c) &&
		!ft_isop(c) && !ft_issep(c) && c != ' ')
		return (1);
	return (0);
}

int			ft_isred(int c)
{
	if (c == 60 || c == 62)
		return (1);
	return (0);
}

int			ft_isop(int c)
{
	if (c == 34 || c == 39)
		return (1);
	return (0);
}

int			ft_issep(int c)
{
	if (c == 124 || c == 38 || c == 59 || c == 96)
		return (1);
	return (0);
}

static char	*ft_type(int c)
{
	char *tmp;

	tmp = NULL;
	if (ft_isalphan(c))
		tmp = ft_strdup("char");
	if (ft_isdigit(c))
		tmp = ft_strdup("int");
	if (ft_isop(c))
		tmp = ft_strdup("op");
	if (ft_issep(c))
		tmp = ft_strdup("sep");
	if (ft_isred(c))
		tmp = ft_strdup("red");
	return (tmp);
}

void		ft_new(char *str, t_lex **cmd, int *i, int (ft_cmp)(int c))
{
	int		start;
	t_lex	*last;
	int		l;
	t_lex	*tmp;

	tmp = ((*cmd)->data) ? *cmd : NULL;
	last = ((*cmd)->data != NULL) ? malloc(sizeof(t_lex)) : *cmd;
	l = *i;
	if (tmp)
		while (tmp->next)
			tmp = tmp->next;
	start = *i;
	while (str[l] != '\n' && ft_cmp(str[l]))
		l++;
	if ((*cmd)->data != NULL)
		tmp->next = last;
	last->data = ft_strsub(str, start, (l - start));
	last->prev = tmp;
	last->type = ft_type(str[start]);
	last->value = (last->prev == NULL || !ft_strcmp(last->prev->type, "sep") ||
	!ft_strcmp(last->type, "sep")) ? 1 : last->prev->value + 1;
	last->next = NULL;
	*i = l;
}
