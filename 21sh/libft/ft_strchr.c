/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 02:02:11 by jukuntzm          #+#    #+#             */
/*   Updated: 2017/12/07 06:39:18 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c2;
	char	*str;

	str = (char *)s;
	i = 0;
	c2 = (char)c;
	while (str[i])
	{
		if (str[i] == c2)
			return (&str[i]);
		i++;
	}
	if (str[i] == c2)
		return (&str[i]);
	return (NULL);
}
