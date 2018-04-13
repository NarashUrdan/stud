/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 07:31:17 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/04/13 19:06:53 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

void	ft_error(t_lex	*cmd, char *str, char *sep)
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

static int	lexer2(t_lex **cmd)
{
	t_lex 	*tmp;
	int		i;

	tmp = *cmd;
	if (ft_issep(tmp->data[0]) && ft_strcmp(tmp->data, ";"))
		ft_error(*cmd, "parse error near", tmp->data); 
	while (tmp)
	{
		free(tmp->type);
		if (ft_isred(tmp->data))
			tmp->type = ft_strdup("red");
		else if ((!tmp->prev || !ft_strcmp(tmp->prev->type, "sep")) &&
				!ft_issep(tmp->data[0]))
			tmp->type = ft_strdup("co");
		else if (tmp->data[0] == '-')
			tmp->type = ft_strdup("op");
		else if ((ft_isalphan(tmp->data[0]) || ft_isdigit(tmp->data[0])) &&
				!ft_isred(tmp->data))
			tmp->type = ft_strdup("arg");
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
//	int		*pipefd;

//	pipefd =(int *)malloc(sizeof(int) * 2);
	tree = malloc(sizeof(t_tree));
	cmd = NULL;
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		if (str[i] != ' ' && str[i] != '\n' && ft_isalphan(str[i]))
			ft_new(str, &cmd, &i, &(ft_isalphan));
		else if (str[i] != '\n' && (str[i + 1] == 60 || str[i + 1] == 62))
			ft_newred(str, &cmd, &i);
		else if (str[i] != ' ' && str[i] != '\n' && ft_isdigit(str[i]))
			ft_new(str, &cmd, &i, &(ft_isdigit));
		else if (str[i] != ' ' && str[i] != '\n' && ft_issep(str[i]))
			ft_new(str, &cmd, &i, &(ft_issep));
		else if (str[i] != '\n' && !ft_isop(str[i]))
		{
			i++;
			ft_new(str, &cmd, &i, &(ft_isop));
			i++;
		}
		else if (str[i] != '\n' && str[i] == ' ')
			i++;
	}
	i = lexer2(&cmd);
	while (cmd->prev)
		cmd = cmd->prev;
	ft_makeabigtree(&cmd, &tree, i);
	while (cmd)
	{
/*		ft_putendl("---data----");
		ft_putendl(cmd->data);
		ft_putendl("---value---");
		ft_putnbr(cmd->value);
		write(1, "\n", 1);
		ft_putendl("---type----");
		ft_putendl(cmd->type);
*/		free(cmd->type);
		free(cmd->data);
		if (cmd->next)
			cmd = cmd->next;
		else
			break ;
		free(cmd->prev);
//		write(1, "\n", 1);
	}
	free(cmd);
	ft_putendl("----DEBUTTREE----");
//	ft_printtree(tree);
	ft_putendl_fd("--EXEC--", 2);
	ft_sep(tree, 0);
//	while(1) ;
//	ft_putendl("a");
	return (0);
}
