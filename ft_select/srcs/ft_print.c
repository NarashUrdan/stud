/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 00:29:27 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/20 10:41:43 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	ft_print(t_ar *arg)
{
	if (!arg)
		exit(EXIT_SUCCESS);
	while (arg)
	{
		if (arg->ghost == 1)
		{
			if (arg->cursor)
				ft_putstr_fd(tgetstr("us", NULL), 0);
			if (arg->select)
				ft_putstr_fd(tgetstr("mr", NULL), 0);
			ft_putstr_fd("[", 0);
			ft_putstr_fd((arg->cursor == 1) ? ">" : " ", 0);
			ft_putstr_fd(arg->name, 0);
			ft_putstr_fd(" ] ", 0);
			ft_putstr_fd(tgetstr("me", NULL), 0);
		}
		arg = arg->next;
	}
}
