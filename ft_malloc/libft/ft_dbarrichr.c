/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbarrichr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm<jukuntzm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 13:36:06 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/05/06 13:37:21 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dbarrichr(char **dbarr, char *str)
{
	int		i;

	i = 0;
	while (dbarr[i] != NULL)
	{
		if (ft_strcmp(dbarr[i], str) == 0)
			return (i);
		i++;
	}
	return (-1);
}
