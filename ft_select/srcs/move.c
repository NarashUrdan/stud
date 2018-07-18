/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 21:44:43 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/27 10:47:25 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void		ft_left(t_ar **arg)
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

static void	ft_down(t_ar **arg, t_size size)
{
	t_ar	*tmp;
	int		i;
	int		val;

	i = size.st_row;
	tmp = *arg;
	while (tmp->next && tmp->cursor == 0)
		tmp = tmp->next;
	tmp->cursor = 0;
	val = tmp->value;
	if (tmp->next)
		tmp = tmp->next;
	else
		while (tmp->prev)
			tmp = tmp->prev;
	while (tmp->value != val)
	{
		if (tmp->next)
			tmp = tmp->next;
		else
			while (tmp->prev)
				tmp = tmp->prev;
	}
	tmp->cursor = 1;
}

static void	ft_up(t_ar **arg, t_size size)
{
	t_ar	*tmp;
	int		i;
	int		val;

	i = size.st_row;
	tmp = *arg;
	while (tmp->next && tmp->cursor == 0)
		tmp = tmp->next;
	tmp->cursor = 0;
	val = tmp->value;
	if (tmp->prev)
		tmp = tmp->prev;
	else
		while (tmp->next)
			tmp = tmp->next;
	while (tmp->value != val)
	{
		if (tmp->prev)
			tmp = tmp->prev;
		else
			while (tmp->next)
				tmp = tmp->next;
	}
	tmp->cursor = 1;
}

void		ft_right(t_ar **arg)
{
	t_ar	*tmp;

	tmp = *arg;
	while (tmp->next && tmp->cursor == 0)
		tmp = tmp->next;
	tmp->cursor = 0;
	while (tmp)
	{
		if (tmp->next || (tmp->next && tmp->next->ghost == 0))
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

t_ar		*ft_arrow(t_ar *arg, char *ret, t_size size)
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
