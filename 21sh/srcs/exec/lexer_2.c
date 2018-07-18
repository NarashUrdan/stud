/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <jukuntzm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 15:40:26 by slegros           #+#    #+#             */
/*   Updated: 2018/05/15 15:17:30 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int		ft_s(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while ((char)s1[i] || (char)s2[i])
	{
		if ((char)s1[i] != (char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

static int		ft_error(t_lex *cmd, char *str, char *sep)
{
	ft_putstr_col_fd(str, YEL, 2);
	ft_putstr_col_fd(" `", YEL, 2);
	ft_putstr_col_fd(sep, YEL, 2);
	ft_putendl_col_fd("'", YEL, 2);
	while (cmd->next)
	{
		free(cmd->data);
		free(cmd->type);
		cmd = cmd->next;
		if (cmd->prev)
			free(cmd->prev);
	}
	free(cmd->data);
	free(cmd->type);
	free(cmd);
	return (-1);
}

static int		lexer2(t_lex **cmd, int i)
{
	t_lex	*tmp;

	tmp = *cmd;
	while (tmp->prev)
		tmp = tmp->prev;
	ft_s(tmp->data, "`");
	if (ft_issep(tmp->data[0]))
		return (ft_error(*cmd, "21sh: Parse error near ", tmp->data));
	while (tmp)
	{
		if (ft_isred(tmp->data) && ft_strcmp(tmp->type, "char"))
			tmp->type = ft_strdupf(tmp->type, "red");
		else if (!tmp->prev || (!ft_strcmp(tmp->prev->type, "sep") &&
			ft_strcmp(tmp->prev->data, "`") && !ft_issep(tmp->data[0])))
			tmp->type = ft_strdupf(tmp->type, "co");
		else if (tmp->data[0] == '-')
			tmp->type = ft_strdupf(tmp->type, "op");
		else if (ft_issep(tmp->data[0]))
			tmp->type = ft_strdupf(tmp->type, "sep");
		else
			tmp->type = ft_strdupf(tmp->type, "arg");
		i = tmp->value;
		tmp = tmp->next;
	}
	return (i);
}

static int		ft_redcheck(char *str, int i)
{
	char	c;

	c = str[i];
	if (ft_issep(str[i]) && str[i] != '&')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			return (0);
		if (str[i] == 62 && ft_isalpha(c))
			return (0);
		if (str[i] == 60 || str[i] == 62)
			return (1);
		i++;
	}
	return (0);
}

t_lex			*ft_lex(char *str, int *l)
{
	t_lex	*cmd;
	int		i;

	cmd = NULL;
	i = 0;
	while (str[i] && str[i] != '\0')
	{
		i = (str[i] == '\n') ? i + 1 : i;
		if (str[i] != '\0' && ft_redcheck(str, i))
			ft_newred(str, &cmd, &i);
		else if (str[i] != '\0' && ft_issep(str[i]))
			ft_new(str, &cmd, &i, &(ft_issep));
		else if (str[i] != '\0' && ft_isalphan(str[i]))
			ft_new(str, &cmd, &i, &(ft_isalphan));
		else if (str[i] != '\0' && !ft_isop(str[i]))
		{
			i++;
			ft_new(str, &cmd, &i, &(ft_isop));
			i = (str[i] != '\0') ? i + 1 : i;
		}
		else if (str[i] != '\0' && (str[i] == ' '))
			i++;
	}
	*l = lexer2(&cmd, 0);
	return (cmd);
}
