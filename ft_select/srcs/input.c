/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 01:52:33 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/27 10:50:50 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void	ft_select(t_ar **arg)
{
	t_ar	*tmp;

	tmp = *arg;
	while (tmp)
	{
		if (tmp->cursor == 1)
		{
			tmp->select = (tmp->select == 0) ? 1 : 0;
			tmp->cursor = 0;
			if (tmp->next)
			{
				tmp->next->cursor = 1;
				return ;
			}
			if (!tmp->next)
			{
				while (tmp->prev)
					tmp = tmp->prev;
				tmp->cursor = 1;
				return ;
			}
		}
		tmp = tmp->next;
	}
}

static int	ft_ghost(t_ar **arg)
{
	t_ar	*tmp;

	tmp = *arg;
	while (tmp)
	{
		if (tmp->ghost == 1 && tmp->cursor == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	ft_del(t_ar **arg, struct termios *term, t_size size)
{
	t_ar	*tmp;

	tmp = (*arg);
	if (ft_ghost(arg))
		ft_exit(arg, term, 1);
	while (tmp)
	{
		if (tmp->cursor == 1)
		{
			tmp->value = 0;
			tmp->ghost = 0;
			(tmp->next) ? ft_right(&tmp) : ft_left(&tmp);
			while (tmp)
			{
				if (tmp->value == 1)
					tmp->value = size.sw_col;
				else if (tmp->value != 0)
					tmp->value = tmp->value - 1;
				tmp = tmp->next;
			}
			break ;
		}
		tmp = tmp->next;
	}
}

static void	ft_resize(t_ar **arg, t_size *size)
{
	ft_getsize(*arg, size);
	ft_putstr_fd(tgetstr("cl", NULL), 0);
	ft_check_value(arg, *size);
	ft_print(*arg, *size);
}

t_ar		*wait_input(t_ar *arg, struct termios *term, t_size size)
{
	char	ret[4];
	int		res;

	if (SIGWINCH)
		ft_resize(&arg, &size);
	if ((res = read(0, &ret, 4)) == -1)
		ft_exit(&arg, term, 0);
	if (ret[0] == 26)
		ft_stop(term);
	if (SIGCONT)
		ft_cont(term);
	if (ret[3] == 126 || ret[0] == 127)
		ft_del(&arg, term, size);
	if ((ret[0] == 27 && ret[2] == '\0') || ret[0] == 3)
		ft_exit(&arg, term, 1);
	if (ret[2] >= 65 && ret[2] <= 68)
		arg = ft_arrow(arg, ret, size);
	if (ret[0] == 32)
		ft_select(&arg);
	if (ret[0] == 10)
		ft_rtn(arg, term);
	ft_bzero(ret, 4);
	return (arg);
}
