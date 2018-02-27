/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 22:41:03 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/27 10:56:04 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	ft_stop(struct termios *term)
{
	char	sup[2];

	sup[0] = term->c_cc[VSUSP];
	sup[1] = '\0';
	ft_unterm(term);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, sup);
}

void	ft_cont(struct termios *term)
{
	ft_term(term);
	ft_putstr_fd(tgetstr("ti", NULL), 0);
	ft_putstr_fd(tgetstr("vi", NULL), 0);
	ft_putstr_fd(tgetstr("cl", NULL), 0);
}

void	ft_getsize(t_ar *arg, t_size *size)
{
	struct winsize	w;
	size_t			s_arg;
	int				i;

	i = 0;
	s_arg = 0;
	ioctl(0, TIOCGWINSZ, &w);
	while (arg)
	{
		if (ft_strlen(arg->name) > s_arg)
			s_arg = ft_strlen(arg->name);
		arg = arg->next;
		i++;
	}
	size->st_row = w.ws_row;
	size->st_col = w.ws_col;
	size->sw_max = (int)s_arg;
	size->sw_col = w.ws_col / ((int)s_arg + 4);
	if (i == 1)
		size->sw_row = 1;
	else if (i % size->sw_col == 0)
		size->sw_row = i / size->sw_col;
	else
		size->sw_row = ((i / size->sw_col) + 1);
}

t_ar	*lst_first(char *name)
{
	t_ar *arg;

	arg = malloc(sizeof(t_ar));
	arg->name = ft_strdup(name);
	arg->cursor = 1;
	arg->ghost = 1;
	arg->select = 0;
	arg->next = NULL;
	arg->prev = NULL;
	arg->value = 1;
	return (arg);
}

void	lst_new(t_ar **arg, char *name, t_size size)
{
	t_ar	*tmp;
	t_ar	*arg2;

	tmp = *arg;
	arg2 = malloc(sizeof(t_ar));
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = arg2;
	arg2->name = ft_strdup(name);
	arg2->cursor = 0;
	arg2->ghost = 1;
	arg2->select = 0;
	arg2->prev = tmp;
	arg2->next = NULL;
	arg2->value = (arg2->prev->value < (size.sw_col) ?
			(arg2->prev->value + 1) : 1);
}
