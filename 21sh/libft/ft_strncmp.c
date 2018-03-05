/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 02:16:31 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/01/16 22:34:16 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1c;
	unsigned char	*s2c;

	s1c = (unsigned char *)s1;
	s2c = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	if (s1c[i] != '\0' && s2c[i] == '\0')
		return (1);
	if (s1c[i] == '\0' && s2c[i] != '\0')
		return (-1);
	while ((s1c[i] != '\0' || s2c[i] != '\0') && i < n)
	{
		if (s1c[i] == s2c[i])
			i++;
		else
			return (s1c[i] - s2c[i]);
	}
	return (0);
}
