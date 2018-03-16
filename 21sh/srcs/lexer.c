/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 07:31:17 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/03/16 16:55:44 by jukuntzm         ###   ########.fr       */
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

static int	lexer2(t_lex **cmd)
{
	t_lex 	*tmp;
	int		i;

	tmp = *cmd;
	while (tmp)
	{
		free(tmp->type);
		if ((!tmp->prev || !ft_strcmp(tmp->prev->type, "sep")) &&
				!ft_issep(tmp->data[0]))
			tmp->type = ft_strdup("co");
		else if (tmp->data[0] == '-')
			tmp->type = ft_strdup("op");
		else if ((ft_isalphan(tmp->data[0]) || ft_isdigit(tmp->data[0])) &&
				!ft_isred(tmp->data))
			tmp->type = ft_strdup("arg");
		else if (ft_isred(tmp->data))
			tmp->type = ft_strdup("red");
		else
			tmp->type = ft_strdup("sep");
		i = tmp->value;
		tmp = tmp->next;
	}
	return (i);
}

int			ft_check(char *str)
{
	int		i;
	t_lex	*cmd;
	t_tree	*tree;

	tree = malloc(sizeof(t_tree));
	cmd = malloc(sizeof(t_lex));
	ft_init(cmd);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		if (str[i] != ' ' && str[i] != '\n' && ft_isalphan(str[i]))
			ft_new(str, &cmd, &i, &(ft_isalphan));
		else if (str[i] != '\n' && ft_isdigit(str[i]) && ft_isred(&str[i + 1]))
			ft_new(str, &cmd, &i, &(ft_isnotspace));
		else if (str[i] != ' ' && str[i] != '\n' && ft_isdigit(str[i]))
			ft_new(str, &cmd, &i, &(ft_isdigit));
		else if (str[i] != ' ' && str[i] != '\n' && ft_issep(str[i]))
			ft_new(str, &cmd, &i, &(ft_issep));
		else if (str[i] != '\n' && ft_isop(str[i]))
			ft_new(str, &cmd, &i, &(ft_isop));
		else if (str[i] != '\n' && str[i] == ' ')
			i++;
	}
	i = lexer2(&cmd);
	while (cmd->prev)
		cmd = cmd->prev;
	ft_makeabigtree(&cmd, &tree, i);
	ft_putendl_fd(tree->cmd, 2);
/*	while (cmd)
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
	}*/
	ft_putendl("----DEBUTTREE----");
	ft_printtree(tree);
	return (0);
}
