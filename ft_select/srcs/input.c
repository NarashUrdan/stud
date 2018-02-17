/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 01:52:33 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/17 05:23:22 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static t_ar *ft_left(t_ar *arg)
{
	while (arg && arg->cursor == 0)
		arg = arg->next;
	arg->cursor = 0;
	arg->prev->cursor = 1;
	return (arg);
}

static t_ar	*ft_right(t_ar *arg)
{
	while (arg && arg->cursor == 0)
		arg = arg->next;
	arg->cursor = 0;
	arg->next->cursor = 1;
	return (arg);
}

static t_ar	*ft_arrow(t_ar *arg, char *ret)
{
	if (ret[2] == 68)
		arg = ft_left(arg);
	else if (ret[2] == 67)
		arg = ft_right(arg);
	return (arg);
}

t_ar	*wait_input(t_ar *arg)
{
	char	ret[5];
	int		res;

	if ((res = read(0, &ret, 5)) == -1)
		exit(EXIT_FAILURE);
	if (ret[2] >= 65 && ret[2] <= 68)
		arg = ft_arrow(arg, ret);
	return (arg);
}
