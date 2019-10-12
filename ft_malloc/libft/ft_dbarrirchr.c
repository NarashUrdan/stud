/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbarrirchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm<jukuntzm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 13:37:51 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/05/06 13:38:30 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dbarrirchr(char **dbarr, char *str)
{
	int		i;

	i = ft_dbarrlen(dbarr);
	while (i >= 0)
	{
		if (ft_strcmp(dbarr[i], str) == 0)
			return (i);
		i--;
	}
	return (-1);
}
