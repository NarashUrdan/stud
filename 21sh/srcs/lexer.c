/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 07:31:17 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/03/07 00:37:36 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

void		ft_init(t_lex *cmd)
{
	cmd->data = NULL;
	cmd->type = NULL;
	cmd->next = NULL;
	cmd->prev = NULL;
	cmd->value = 0;
}

static void	lexer2(t_lex **cmd)
{
	t_lex *tmp;

	tmp = *cmd;
	while (tmp)
	{
		free(tmp->type);
		if (tmp->value == 1 && !ft_issep(tmp->data[0]) &&
			!ft_isdigit(tmp->data[0]))
			tmp->type = ft_strdup("command");
		else if (tmp->value == 2 && tmp->data[0] == '-')
			tmp->type = ft_strdup("command option");
		else if ((tmp->value > 1 && ft_isalphan(tmp->data[0])) ||
			ft_isdigit(tmp->data[0]))
			tmp->type = ft_strdup("arg");
		else if (ft_isred(tmp->data[0]))
			tmp->type = ft_strdup("redirection");
		else
			tmp->type = ft_strdup("sep");
		tmp = tmp->next;
	}
}

int			ft_check(char *str)
{
	int		i;
	t_lex	*cmd;

	cmd = malloc(sizeof(t_lex));
	ft_init(cmd);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		if (str[i] != ' ' && str[i] != '\n' && ft_isalphan(str[i]))
			ft_new(str, &cmd, &i, &(ft_isalphan));
		else if (str[i] != ' ' && str[i] != '\n' && ft_isdigit(str[i]))
			ft_new(str, &cmd, &i, &(ft_isdigit));
		else if (str[i] != ' ' && str[i] != '\n' && ft_issep(str[i]))
			ft_new(str, &cmd, &i, &(ft_issep));
		else if (str[i] != '\n' && ft_isop(str[i]))
			ft_new(str, &cmd, &i, &(ft_isop));
		else if (str[i] != '\n' && ft_isred(str[i]))
			ft_new(str, &cmd, &i, &(ft_isred));
		else if (str[i] != '\n' && str[i] == ' ')
			i++;
	}
	lexer2(&cmd);
	while (cmd)
	{
		ft_putendl("---data----");
		ft_putendl(cmd->data);
		ft_putendl("---value---");
		ft_putnbr(cmd->value);
		write(1, "\n", 1);
		ft_putendl("---type----");
		ft_putendl(cmd->type);
		free(cmd->type);
		free(cmd->data);
		if (cmd->next)
			cmd = cmd->next;
		else
			break ;
		free(cmd->prev);
		write(1, "\n", 1);
	}
	return (0);
}
