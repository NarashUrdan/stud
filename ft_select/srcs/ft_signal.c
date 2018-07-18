/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 07:16:39 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/27 09:48:08 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void	ft_signal_quit(int c)
{
	struct termios term;

	if (c)
	{
		term = ft_get_env();
		ft_putstr_fd(tgetstr("me", NULL), 0);
		ft_putstr_fd(tgetstr("cl", NULL), 0);
		ft_putstr_fd(tgetstr("te", NULL), 0);
		ft_putstr_fd(tgetstr("ve", NULL), 0);
		term.c_lflag |= ICANON | ISIG;
		term.c_lflag |= ECHO;
		tcsetattr(0, TCSADRAIN, &term);
		exit(EXIT_FAILURE);
	}
}

void		ft_signal(void)
{
	signal(SIGINT, ft_signal_quit);
	signal(SIGHUP, ft_signal_quit);
	signal(SIGQUIT, ft_signal_quit);
	signal(SIGILL, ft_signal_quit);
	signal(SIGTRAP, ft_signal_quit);
	signal(SIGABRT, ft_signal_quit);
	signal(SIGBUS, ft_signal_quit);
	signal(SIGKILL, ft_signal_quit);
	signal(SIGSEGV, ft_signal_quit);
	signal(SIGPIPE, ft_signal_quit);
	signal(SIGTERM, ft_signal_quit);
	signal(SIGXFSZ, ft_signal_quit);
	signal(SIGSYS, ft_signal_quit);
	signal(SIGALRM, ft_signal_quit);
	signal(SIGXCPU, ft_signal_quit);
	signal(SIGVTALRM, ft_signal_quit);
}
