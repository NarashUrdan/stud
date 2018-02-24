/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 21:18:49 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/24 06:21:19 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static struct termios	ft_get_env(void)
{
	char					*env;
	static struct termios	term;

	if ((env = getenv("TERM")) == NULL)
	{
		ft_putendl_fd("error", 2);
		exit(EXIT_FAILURE);
	}
	if (tgetent(NULL, env) < 1)
	{
		ft_putendl_fd("error", 2);
		exit(EXIT_FAILURE);
	}
	if (tcgetattr(0, &term) == -1)
	{
		ft_putendl_fd("error", 2);
		exit(EXIT_FAILURE);
	}
	return (term);
}

static void				ft_term(struct termios *term)
{
	term->c_lflag &= ~(ICANON | ISIG);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		ft_exit(NULL, term, 0);
}

int						main(int argc, char **argv)
{
	int						i;
	t_ar					*arg;
	static struct termios	term;
	t_size					size;

	if (argc == 1)
		return (0);
	term = ft_get_env();
	ft_term(&term);
	arg = lst_first(argv[1]);
	i = 1;
	while (argv[++i])
		lst_new(&arg, argv[i]);
	while (1)
	{
		ft_getsize(arg, &size);
		ft_putstr_fd(tgetstr("vi", NULL), 0);
		ft_putstr_fd(tgetstr("ti", NULL), 0);
		ft_putstr_fd(tgetstr("cl", NULL), 0);
		ft_print(arg, size);
		arg = wait_input(arg, &term, size);
		ft_putstr_fd(tgetstr("cl", NULL), 0);
	}
	ft_unterm(&term);
	return (0);
}
