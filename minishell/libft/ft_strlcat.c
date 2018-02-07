/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 02:12:20 by jukuntzm          #+#    #+#             */
/*   Updated: 2017/11/15 04:21:13 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	i2;
	char	*str;

	str = (char *)src;
	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dest[i] != '\0' && i < size)
		i++;
	i2 = i;
	while (str[i - i2] && i < size - 1)
	{
		dest[i] = str[i - i2];
		i++;
	}
	if (i2 < size)
		dest[i] = '\0';
	return (i2 + ft_strlen(src));
}
