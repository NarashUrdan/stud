/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 00:29:27 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/23 08:50:40 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	ft_unterm(struct termios *term)
{
	term->c_lflag |= ICANON;
	term->c_lflag |= ECHO;
	tcsetattr(0, 0, term);
	ft_putstr_fd(tgetstr("me", NULL), 1);
	ft_putstr_fd(tgetstr("cl", NULL), 1);
	ft_putstr_fd(tgetstr("ve", NULL), 1);
}

void	ft_exit(t_ar **arg, struct termios *term, int mode)
{
	while (*arg)
	{
		free((*arg)->name);
		(*arg) = (*arg)->next;
	}
	free(*arg);
	ft_unterm(term);
	if (mode)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}

void	ft_rtn(t_ar *arg, struct termios *term)
{
	while (arg)
	{
		if (arg->select == 1)
		{
			ft_putstr(arg->name);
			write(1, " ", 1);
		}
		arg = arg->next;
	}
	ft_exit(&arg, term, 1);
}
/*static	int	ft_sizeterm(t_ar *arg, struct winsize *w)
{
	size_t size;
	int		i;

	i = 0;
	size = 0;
	while (arg)
	{
		if (ft_strlen(arg->name) > size)
			size = ft_strlen(arg->name);
		arg = arg->next;
		i++;
	}
	ioctl(0, TIOCGWINSZ, w);
	if (w->ws_col < size || w->ws_row < i)
		return (0);
	return (1);
}
*/
void	ft_print(t_ar *arg, t_size size)
{
	int	i;
	int sw;
	int	s;

	s = 0;
	if (!arg)
		exit(EXIT_SUCCESS);
	if ((size.sw_max < (size.st_col - 4)) && (size.sw_col <= size.st_row))
	{
		while (arg)
		{
			i = -1;
			sw = size.sw_max - (int)ft_strlen(arg->name);
			if (arg->ghost == 1)
			{
				if ((s + size.sw_max + 4) >= size.st_col)
				{
					write(1, "\n", 1);
					s = 0;
				}
				if (arg->cursor)
					ft_putstr_fd(tgetstr("us", NULL), 0);
				if (arg->select)
					ft_putstr_fd(tgetstr("mr", NULL), 0);
				ft_putstr_fd("[", 1);
				ft_putstr_fd((arg->cursor == 1) ? ">" : " ", 1);
				while (((int)ft_strlen(arg->name) != size.st_col) && ++i < sw/2)
					ft_putstr_fd(" ", 1);
				ft_putstr_fd(arg->name, 1);
				while (((int)ft_strlen(arg->name) != size.st_col) && ++i <= sw)
					ft_putstr_fd(" ", 1);
				ft_putstr_fd(" ]", 1);
				ft_putstr_fd(tgetstr("me", NULL), 1);
				s = s + size.sw_max + 4;
			}
			arg = arg->next;
		}
	}
	else
		ft_putstr_fd("Terminal trop petit.", 2);
}
