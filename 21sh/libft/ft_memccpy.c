/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 00:35:49 by jukuntzm          #+#    #+#             */
/*   Updated: 2017/12/02 06:35:22 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	char		*str;
	char		*str2;

	str2 = (char *)dest;
	str = (char *)src;
	i = 0;
	while (i < n)
	{
		str2[i] = str[i];
		if (str[i] == (char)c)
			return (&str2[i + 1]);
		i++;
	}
	return (NULL);
}
