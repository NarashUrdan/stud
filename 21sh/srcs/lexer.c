/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 07:31:17 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/04/19 17:58:40 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

void			ft_error(t_lex *cmd, char *str, char *sep)
{
	ft_putstr_fd(str, 2);
	write(2, " '", 2);
	ft_putstr_fd(sep, 2);
	write(2, "'\n", 2);
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
	exit(EXIT_FAILURE);
}

static int		lexer2(t_lex **cmd)
{
	t_lex	*tmp;
	int		i;

	tmp = *cmd;
	if (ft_issep(tmp->data[0]) && ft_strcmp(tmp->data, ";"))
		ft_error(*cmd, "parse error near", tmp->data);
	while (tmp)
	{
		free(tmp->type);
		if (ft_isred(tmp->data))
			tmp->type = ft_strdup("red");
		else if (!tmp->prev ||
			(!ft_strcmp(tmp->prev->type, "sep") &&
			 ft_strcmp(tmp->prev->data, "`") && !ft_issep(tmp->data[0])))
			tmp->type = ft_strdup("co");
		else if (tmp->data[0] == '-')
			tmp->type = ft_strdup("op");
		else if (ft_issep(tmp->data[0]))
			tmp->type = ft_strdup("sep");
		else
			tmp->type = ft_strdup("arg");
		i = tmp->value;
		tmp = tmp->next;
	}
	return (i);
}

static t_lex	*ft_lex(char *str, int *l)
{
	t_lex	*cmd;
	int		i;

	cmd = NULL;
	i = 0;
	while (str[i] && str[i] != '\0')
	{
		if (str[i] != '\0' && ft_issep(str[i]))
			ft_new(str, &cmd, &i, &(ft_issep));
		else if (str[i] != '\0' && ft_isalphan(str[i]))
			ft_new(str, &cmd, &i, &(ft_isalphan));
		else if (str[i] != '\0' && !ft_isop(str[i]))
		{
			i++;
			ft_new(str, &cmd, &i, &(ft_isop));
			i++;
		}
		else if (str[i] != '\0' && (str[i + 1] == 60 || str[i + 1] == 62))
			ft_newred(str, &cmd, &i);
		else if (str[i] != '\0' && str[i] == ' ')
			i++;
		ft_checkdata(&cmd);
	}
	i = lexer2(&cmd);
	*l = i;
	return (cmd);
}

int				ft_check(char *str)
{
	t_tree	*tree;
	t_lex	*cmd;
	int		i;

	i = 0;
	if (!(tree = malloc(sizeof(t_tree))))
		return (1);
	cmd = ft_lex(str, &i);
	while (cmd->prev)
		cmd = cmd->prev;
	ft_makeabigtree(&cmd, &tree, i);
	while (cmd)
	{
//		ft_putendl("---data---");
//		ft_putendl(cmd->data);
//		ft_putendl("---type---");
//		ft_putendl(cmd->type);
		free(cmd->type);
		free(cmd->data);
		if (cmd->next)
			cmd = cmd->next;
		else
			break ;
		free(cmd->prev);
	}
//	ft_print_words_tables(tree->args);
	free(cmd);
//	ft_printtree(tree);
	ft_sep(tree, 0);
//	while (1);
	return (0);
}
