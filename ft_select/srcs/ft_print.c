/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 00:29:27 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/27 11:07:32 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void		ft_unterm(struct termios *term)
{
	ft_putstr_fd(tgetstr("me", NULL), 0);
	ft_putstr_fd(tgetstr("cl", NULL), 0);
	ft_putstr_fd(tgetstr("te", NULL), 0);
	ft_putstr_fd(tgetstr("ve", NULL), 0);
	term->c_lflag |= ICANON | ISIG;
	term->c_lflag |= ECHO;
	tcsetattr(0, TCSADRAIN, term);
}

void		ft_exit(t_ar **arg, struct termios *term, int mode)
{
	t_ar	*tmp;

	tmp = *arg;
	ft_unterm(term);
	if (mode)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}

void		ft_rtn(t_ar *arg, struct termios *term)
{
	int i;

	i = 0;
	ft_unterm(term);
	while (arg)
	{
		if (arg->select == 1)
		{
			if (i > 0)
				write(1, " ", 1);
			ft_putstr_fd(arg->name, 1);
			i++;
		}
		arg = arg->next;
	}
	write(1, "\n", 1);
	exit(EXIT_SUCCESS);
}

static void	ft_write(t_ar *arg, t_size size, int sw)
{
	int	i;

	i = -1;
	if (arg->cursor)
		ft_putstr_fd(tgetstr("us", NULL), 0);
	if (arg->select)
		ft_putstr_fd(tgetstr("mr", NULL), 0);
	ft_putstr_fd("[", 0);
	ft_putstr_fd((arg->cursor == 1) ? ">" : " ", 0);
	while (((int)ft_strlen(arg->name) != size.st_col) && ++i < sw / 2)
		ft_putstr_fd(" ", 0);
	ft_putstr_fd(arg->name, 0);
	while (((int)ft_strlen(arg->name) != size.st_col) && ++i <= sw)
		ft_putstr_fd(" ", 0);
	ft_putstr_fd(" ]", 0);
	ft_putstr_fd(tgetstr("me", NULL), 0);
}

void		ft_print(t_ar *arg, t_size size)
{
	int sw;
	int	s;

	s = 0;
	if ((size.sw_max < (size.st_col - 4)) && (size.sw_row <= size.st_row))
	{
		while (arg)
		{
			sw = size.sw_max - (int)ft_strlen(arg->name);
			if (arg->ghost == 1)
			{
				if ((s + size.sw_max + 4) >= size.st_col)
				{
					write(0, "\n", 1);
					s = 0;
				}
				ft_write(arg, size, sw);
				s = s + size.sw_max + 4;
			}
			arg = arg->next;
		}
	}
	else
		ft_putstr_fd("Too small.", 0);
}
