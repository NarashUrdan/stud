/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <jukuntzm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 07:31:17 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/05/15 16:34:56 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int		ft_checkcmd_error(char *data, t_lex **cmd, int mode)
{
	ft_putstr_col_fd("21sh: Parse error near `", YEL, 2);
	if (mode == 0)
		ft_putstr_col_fd(data, YEL, 2);
	else
		ft_putchar_col_fd(*data, YEL, 2);
	ft_putendl_col_fd("'", YEL, 2);
	ft_freecmd(cmd);
	return (1);
}

void			ft_checkcmd_norme(t_lex *tmp, int *l)
{
	free(tmp->data);
	free(tmp->type);
	tmp = tmp->prev;
	free(tmp->next);
	tmp->next = NULL;
	*l = *l - 1;
}

static int		ft_checkcmd(t_lex **cmd, int *l)
{
	t_lex	*tmp;
	int		i;

	i = 0;
	tmp = *cmd;
	while (tmp != NULL)
	{
		if ((i = ft_check_redtmp(tmp)) > 0)
		{
			if (i == 1)
				return (ft_checkcmd_error(tmp->data, cmd, 0));
			else
				return (ft_checkcmd_error(
				&(tmp->data[ft_strichr(tmp->data, (char)i)]), cmd, 1));
		}
		else if (!ft_strcmp(tmp->data, ";") && tmp->next == NULL)
		{
			ft_checkcmd_norme(tmp, l);
			break ;
		}
		tmp = tmp->next;
	}
	return (0);
}

static int		ft_check_norme(int ret)
{
	ft_term(1);
	return (ret);
}

int				ft_check(char *str)
{
	t_tree	*tree;
	t_lex	*cmd;
	int		i;

	i = 0;
	ft_term_reset();
	get_terminal();
	cmd = ft_lex(str, &i);
	if (i == -1)
		return (ft_check_norme(258));
	while (cmd->prev)
		cmd = cmd->prev;
	if (ft_checkcmd(&cmd, &i) == 1)
		return (ft_check_norme(258));
	if (!(tree = malloc(sizeof(t_tree))))
		return (ft_check_norme(1));
	ft_makeabigtree(&cmd, &tree, i);
	ft_freecmd(&cmd);
	ft_i(1, 0);
	i = ft_sep(tree, 0);
	ft_printtree(tree);
	ft_term(1);
	restore_fds();
	return (i);
}
