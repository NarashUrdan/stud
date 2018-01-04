/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 02:19:40 by jukuntzm          #+#    #+#             */
/*   Updated: 2017/12/09 01:21:58 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	i = (int)size;
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i >= 0)
	{
		str[i] = '\0';
		i--;
	}
	return (str);
}
