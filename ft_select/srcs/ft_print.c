/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 00:29:27 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/17 00:35:40 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	ft_print(t_ar *arg)
{
	while (arg)
	{
		ft_putstr_fd("[", 0);
		ft_putstr_fd((arg->cursor == 1) ? ">" : " ", 0);
		ft_putstr_fd(arg->name, 0);
		ft_putstr_fd(" ] ", 0);
		arg = arg->next;
	}
}
