/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 01:52:33 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/19 08:46:25 by jukuntzm         ###   ########.fr       */
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
	if (tmp->prev)
		tmp->prev->cursor = 1;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->cursor = 1;
	}
}

static void ft_right(t_ar **arg)
{
	t_ar	*tmp;

	tmp = *arg;
	while (tmp->next && tmp->cursor == 0)
		tmp = tmp->next;
	tmp->cursor = 0;
	if (tmp->next)
		tmp->next->cursor = 1;
	else
	{
		while (tmp->prev)
			tmp = tmp->prev;
		tmp->cursor = 1;
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

static t_ar	*ft_arrow(t_ar *arg, char *ret)
{
	if (ret[2] == 68)
		ft_left(&arg);
	else if (ret[2] == 67)
		ft_right(&arg);
	return (arg);
}

static void	ft_del(t_ar **arg)
{
	t_ar	*tmp;

	tmp = (*arg);
	while (tmp)
	{
		if (tmp->cursor == 1)
		{
			if (!(tmp->next))
			{
				if (!tmp->prev)
				{
					tmp->name = NULL;
					tmp = tmp->next;
				}
				else
				{
					tmp->name = NULL;
					tmp->prev->next = NULL;
					tmp->prev->cursor = 1;
					tmp->select = 0;
				}
				break ;
			}
			tmp->select = tmp->next->select;
			tmp->next->prev = tmp->prev;
			tmp->name = tmp->next->name;		
			tmp->next->cursor = 1;
			tmp->next = tmp->next->next;
			break ;
		}
		if (tmp->next)
			tmp = tmp->next;
	}
}

t_ar	*wait_input(t_ar *arg)
{
	char	ret[4];
	int		res;

	if ((res = read(0, &ret, 4)) == -1)
		exit(EXIT_FAILURE);
	if (ret[0] == 127)
		ft_del(&arg);
	if (arg->name == NULL  || (ret[0] == 27 && ret[1] == '\0'))
		exit(EXIT_SUCCESS);
	if (ret[2] >= 65 && ret[2] <= 68)
		arg = ft_arrow(arg, ret);
	if (ret[0] == 32)
		ft_select(&arg);
	ft_bzero(ret, 4);
	return (arg);
}
