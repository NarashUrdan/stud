/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 02:03:51 by jukuntzm          #+#    #+#             */
/*   Updated: 2017/11/14 00:52:00 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*s1c;
	unsigned char	*s2c;

	s1c = (unsigned char *)s1;
	s2c = (unsigned char *)s2;
	i = 0;
	if (s1c[i] != '\0' && s2c[i] == '\0')
		return (1);
	if (s1c[i] == '\0' && s2c[i] != '\0')
		return (-1);
	while (s1c[i] != '\0' || s2c[i] != '\0')
	{
		if (s1c[i] == s2c[i])
			i++;
		else
			return (s1c[i] - s2c[i]);
	}
	return (0);
}
