/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:10:29 by jukuntzm          #+#    #+#             */
/*   Updated: 2017/11/14 00:35:11 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *zob;
	int i;
	int mi;

	mi = min;
	i = 0;
	if (mi >= max)
		return (NULL);
	if (!(zob = (int *)malloc(sizeof(int) * max - min)))
		return (NULL);
	while (mi < max)
	{
		zob[i] = mi;
		mi++;
		i++;
	}
	return (zob);
}
