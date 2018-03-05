/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freedoublearray.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 23:28:24 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/13 07:40:44 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freedoublearray(char **array)
{
	unsigned int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i] != NULL)
	{
		ft_memdel((void **)&array[i]);
		i++;
	}
	if (array)
		ft_memdel((void **)&array);
}
