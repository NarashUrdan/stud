/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 02:21:13 by jukuntzm          #+#    #+#             */
/*   Updated: 2017/12/07 01:55:44 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	c2;
	char	*str;

	str = (char *)s;
	i = 0;
	c2 = (char)c;
	i = (int)ft_strlen((const char *)s);
	if (c2 == '\0')
		return (&str[i]);
	while (i >= 0)
	{
		if (str[i] == c2)
			return (&str[i]);
		i--;
	}
	return (NULL);
}
