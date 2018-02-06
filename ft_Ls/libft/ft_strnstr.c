/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 02:20:22 by jukuntzm          #+#    #+#             */
/*   Updated: 2017/11/14 01:01:35 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *s, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (s[i] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && i < len)
	{
		while (str[i + j] == s[j] && (i + j) < len && str[i + j])
		{
			j++;
			if (s[j] == '\0')
				return ((char *)&str[i]);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
