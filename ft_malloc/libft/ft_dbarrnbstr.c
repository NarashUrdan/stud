/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbarrnbstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm<jukuntzm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 13:33:38 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/05/06 13:35:15 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dbarrnbstr(char **dbarr, char *str)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (dbarr[i] != NULL)
	{
		if (ft_strcmp(dbarr[i], str) == 0)
			res++;
		i++;
	}
	return (res);
}
