/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 22:41:03 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/20 10:41:41 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

t_ar *lst_first(char *name)
{
	t_ar *arg;

	arg = malloc(sizeof(t_ar));
	arg->name = ft_strdup(name);
	arg->cursor = 1;
	arg->ghost = 1;
	arg->select = 0;
	arg->next = NULL;
	arg->prev = NULL;
	return (arg);
}

void	lst_new(t_ar **arg, t_ar *arg2, char *name)
{
	t_ar	*tmp;

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
}
