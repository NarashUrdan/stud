/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <jukuntzm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:10:06 by slegros           #+#    #+#             */
/*   Updated: 2018/05/15 17:12:46 by jukuntzm         ###   ########.fr       */
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

static int		ft_checkcmd(t_lex **cmd)
{
	t_lex	*tmp;
	int		i;

	i = 0;
	tmp = *cmd;
	while (tmp)
	{
		tmp->data = ft_strtrimf(tmp->data);
		if (!ft_strcmp(tmp->data, ";") && tmp->next == NULL)
		{
			ft_checkcmd_norme(tmp, &i);
			break ;
		}
		else if ((i = ft_check_redtmp(tmp)) > 0)
		{
			if (i == 1)
				return (ft_checkcmd_error(tmp->data, cmd, 0));
			else
				return (ft_checkcmd_error(
				&(tmp->data[ft_strichr(tmp->data, (char)i)]), cmd, 1));
		}
		tmp = tmp->next;
	}
	return (0);
}

static char		*ft_proper_line(char *line)
{
	char	*tmp;

	tmp = ft_strdup(line);
	while (ft_strichr(tmp, '\n') != -1)
		tmp[ft_strichr(tmp, '\n')] = ' ';
	return (tmp);
}

static int		ft_check_norme(void)
{
	ft_exit_value(1, 258);
	ft_where(2, NULL);
	ft_where(1, NULL);
	return (1);
}

int				ft_inread_parsing(char *line)
{
	int		i;
	t_lex	*cmd;
	char	*tmp;

	if (ft_onlyspc(line) == 1)
		return (0);
	i = 0;
	tmp = ft_proper_line(line);
	cmd = ft_lex(tmp, &i);
	free(tmp);
	if (i == -1)
		return (ft_check_norme());
	while (cmd->prev)
		cmd = cmd->prev;
	if ((i = ft_checkcmd(&cmd)) == 1)
		return (ft_check_norme());
	ft_freecmd(&cmd);
	return (0);
}
