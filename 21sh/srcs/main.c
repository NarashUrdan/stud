/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegros <slegros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:35:34 by slegros           #+#    #+#             */
/*   Updated: 2018/05/08 16:21:07 by slegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_launchshell(void)
{
	char	*line;

	while (42)
	{
		ft_putstr_col_fd(ft_where(0, NULL), BOLD, 0);
		line = ft_get_entry();
		if (line != NULL)
		{
			ft_exit_value(1, ft_check(line));
			free(line);
		}
		ft_heredoc(NULL, 0, 4);
	}
}

int			main(void)
{
	char			**env;

	env = ft_get_env();
	ft_env(env, 1);
	ft_term_check(env);
	ft_term(3);
	ft_term(2);
	ft_term(1);
	ft_history(1, NULL, 0);
	ft_putstr_fd(tgetstr("ti", NULL), 0);
	ft_putstr_fd(tgetstr("cl", NULL), 0);
	ft_welcome(env);
	ft_where(1, NULL);
	ft_get_winsize(1);
	ft_signal();
	ft_path(1, NULL);
	ft_launchshell();
	return (0);
}
