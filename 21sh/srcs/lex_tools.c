/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 08:06:01 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/03/21 15:24:03 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

int			ft_isalphan(int c)
{
	if (!ft_isdigit(c) && ft_isop(c) && !ft_issep(c) && c != ' ')
		return (1);
	return (0);
}

int			ft_isnotspace(int c)
{
	if (c == ' ' || c == '\t')
		return (0);
	return (1);
}

int			ft_isred(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 60 || str[i] == 62)
			return (1);
		i++;
	}
	return (0);
}

int			ft_isop(int c)
{
	if (c == 34 || c == 39)
		return (0);
	return (1);
}

int			ft_issep(int c)
{
	if (c == 124 || c == 38 || c == 59 || c == 96)
		return (1);
	return (0);
}

static char	*ft_type(int c)
{
	if (ft_isalphan(c))
		return("char");
	else if (ft_isdigit(c))
		return("int");
	else if (ft_isop(c))
		return("op");
	else if (ft_issep(c))
		return("sep");
	else
		return (NULL);
}
/*void		ft_rednew(t_lex **last)
{
	char	*op;
	char	*args;
	int		i;
	t_lex	*tmp;

	tmp = *last;
	while (tmp->next)
		tmp = tmp->next;
	i = 1;
	op = ft_strsub(tmp->data, 0, 1);
	while (ft_isred(tmp->data[i]))
		i++;
	args = ft_strsub(tmp->data, i, (ft_strlen(tmp->data) - i));
	tmp = tmp->next;
	tmp->data = ft_strdup(op);
i
}
*/
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
	last->type = ft_strdup(ft_type(str[start]));
	last->value = (last->prev == NULL) ? 1 : last->prev->value + 1;
	last->next = NULL;
	*i = l;
}
