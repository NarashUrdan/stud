/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 21:49:32 by jukuntzm          #+#    #+#             */
/*   Updated: 2017/11/14 00:30:26 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (s)
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		if (s[i] == '\0')
			return (ft_strnew(0));
		j = i;
		while (s[j] != '\0')
			j++;
		while (s[j - 1] == ' ' || s[j - 1] == '\t' || s[j - 1] == '\n')
			j--;
		j--;
		return (ft_strsub(s, i, (j - i) + 1));
	}
	return (NULL);
}
