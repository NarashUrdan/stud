/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <jukuntzm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 08:06:01 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/05/12 13:24:11 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			ft_newdata(t_lex **cmd, char c)
{
	int		i;
	t_lex	*last;
	char	*str;
	t_lex	*tmp;

	if (!(last = malloc(sizeof(t_lex))))
		return ;
	tmp = *cmd;
	while (tmp && tmp->next != NULL)
		tmp = tmp->next;
	i = 0;
	while (tmp->data[i] == c)
		i++;
	tmp->next = last;
	last->data = ft_strsub(tmp->data, i, (ft_strlen(tmp->data) - i));
	last->next = NULL;
	last->prev = tmp;
	last->type = ft_strdup("op");
	str = ft_strdup(tmp->data);
	free(tmp->data);
	tmp->data = ft_strsub(str, 0, i);
	ft_checkdata(cmd);
	free(str);
}

void			ft_checkdata(t_lex **cmd)
{
	char	c;
	int		i;
	t_lex	*tmp;

	tmp = *cmd;
	i = 0;
	while (tmp->next)
		tmp = tmp->next;
	if (ft_strcmp(tmp->type, "op"))
		return ;
	c = tmp->data[0];
	while (tmp->data[i] == c)
		i++;
	if (i != (int)ft_strlen(tmp->data))
		ft_newdata(cmd, c);
}

static t_lex	*ft_newred2(int l, t_lex **cmd, int start, char *str)
{
	t_lex	*last;

	if (!(last = malloc(sizeof(t_lex))))
		return (NULL);
	last->data = ft_strsub(str, start, (l - start));
	last->prev = (*cmd) ? *cmd : NULL;
	last->type = ft_strdup("red");
	last->value = (last->prev == NULL) ? 1 : last->prev->value + 1;
	last->next = NULL;
	return (last);
}

void			ft_newred(char *str, t_lex **cmd, int *i)
{
	int		start;
	t_lex	*last;
	int		l;

	l = *i;
	last = NULL;
	while (*cmd && (*cmd)->next != NULL)
		*cmd = (*cmd)->next;
	start = *i;
	while (str[l] != '\0' && str[l] != ' ' && (str[l] != 60 || str[l] != 62)
		&& (!ft_issep(str[l]) || str[l] == '&'))
		l++;
	if (str[l - 1] == 60 || str[l - 1] == 62 || str[l - 1] == 38)
		while (str[l] != '\0' && str[l] == ' ')
			l++;
	while (str[l] != '\0' && str[l] != ' ' && str[l] != '>' && str[l] != '<' &&
		(!ft_issep(str[l]) || str[l] == '&'))
		l++;
	last = ft_newred2(l, cmd, start, str);
	if (*cmd != NULL)
		(*cmd)->next = last;
	else
		(*cmd) = last;
	*i = l;
}

void			ft_new(char *str, t_lex **cmd, int *i, int (ft_cmp)(int c))
{
	int		start;
	t_lex	*last;
	int		l;
	t_lex	*tmp;

	tmp = *cmd;
	if (!(last = malloc(sizeof(t_lex))))
		return ;
	l = *i;
	while (tmp && tmp->next != NULL)
		tmp = tmp->next;
	start = *i;
	while ((str[l] != '\0' && ft_cmp(str[l])) || (str[l - 1] == 92))
		l++;
	if (tmp != NULL)
		tmp->next = last;
	else
		*cmd = last;
	last->data = ft_strsub(str, start, (l - start));
	last->prev = tmp;
	last->type = ft_strdup(ft_type(str[start]));
	last->value = (last->prev == NULL) ? 1 : last->prev->value + 1;
	last->next = NULL;
	*i = l;
}
