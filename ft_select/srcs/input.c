/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 01:52:33 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/23 08:50:42 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void	ft_left(t_ar **arg)
{
	t_ar	*tmp;

	tmp = *arg;
	while (tmp->next && tmp->cursor == 0)
		tmp = tmp->next;
	tmp->cursor = 0;
	while (tmp)
	{
		if (tmp->prev || (tmp->prev && tmp->prev->ghost == 0))
				tmp = tmp->prev;
		else if (!tmp->prev)
		{
			while (tmp->next)
				tmp = tmp->next;
		}
		if (tmp && tmp->ghost == 1)
		{
			tmp->cursor = 1;
			break ;
		}
	}
}

static void ft_down(t_ar **arg, t_size size)
{
	t_ar	*tmp;
	int		i;

	i = 0;
	tmp = *arg;
	while (tmp->next && tmp->cursor == 0)
		tmp = tmp->next;
	tmp->cursor = 0;
	while (tmp)
	{
		if (tmp->next || (tmp->next &&  tmp->next->ghost == 0))
		{
			tmp = tmp->next;
			i++;
		}
		else if (!tmp->next)
		{
			while (tmp->prev)
				tmp = tmp->prev;
			i = size.sw_col + 1;
		}
		if (i > size.sw_col && tmp && tmp->ghost == 1)
		{
			tmp->cursor = 1;
			break ;
		}
		i++;
	}
}

static void ft_up(t_ar **arg, t_size size)
{
	t_ar	*tmp;
	int		i;

	i = 0;
	tmp = *arg;
	while (tmp->next && tmp->cursor == 0)
		tmp = tmp->next;
	tmp->cursor = 0;
	while (tmp)
	{
		if (tmp->prev || (tmp->prev &&  tmp->prev->ghost == 0))
		{
			tmp = tmp->prev;
			i++;
		}
		else if (!tmp->prev)
		{
			while (tmp->next)
				tmp = tmp->next;
			i = size.sw_col + 1;
		}
		if (i > size.sw_col && tmp && tmp->ghost == 1)
		{
			tmp->cursor = 1;
			break ;
		}
		i++;
	}
}

static void ft_right(t_ar **arg)
{
	t_ar	*tmp;

	tmp = *arg;
	while (tmp->next && tmp->cursor == 0)
		tmp = tmp->next;
	tmp->cursor = 0;
	while (tmp)
	{
		if (tmp->next || (tmp->next &&  tmp->next->ghost == 0))
			tmp = tmp->next;
		else if (!tmp->next)
		{
			while (tmp->prev)
				tmp = tmp->prev;
		}
		if (tmp && tmp->ghost == 1)
		{
			tmp->cursor = 1;
			break ;
		}
	}
}
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

static t_ar	*ft_arrow(t_ar *arg, char *ret, t_size size)
{
	if (ret[2] == 68)
		ft_left(&arg);
	else if (ret[2] == 67)
		ft_right(&arg);
	else if (ret[2] == 66)
		ft_down(&arg, size);
	else if (ret[2] == 65)
		ft_up(&arg, size);
	return (arg);
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

static void	ft_del(t_ar **arg, struct termios *term)
{
	t_ar	*tmp;
	t_ar	*gst;

	gst = (*arg);
	tmp = (*arg);
	if (ft_ghost(arg))
		ft_exit(arg, term, 1);
	while (tmp)
	{
		if (tmp->cursor == 1)
		{
			tmp->ghost = 0;
			ft_right(arg);
			break ;
		}
		tmp = tmp->next;
	}
}

t_ar	*wait_input(t_ar *arg, struct termios *term, t_size size)
{
	char	ret[4];
	int		res;

	if ((res = read(0, &ret, 4)) == -1)
		ft_exit(&arg, term,  0);
	if (ret[3] == 126 || ret[0] == 127)
		ft_del(&arg, term);
	if ((ret[0] == 27 && ret[1] == '\0') || ret[0] == 3)
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
