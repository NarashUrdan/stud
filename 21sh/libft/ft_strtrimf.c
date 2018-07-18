/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <jukuntzm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 13:38:08 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/05/15 16:29:07 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimf(char *s)
{
	unsigned int	i;
	unsigned int	j;

	if (s)
	{
		i = 0;
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		if (s[i] == '\0')
		{
			free(s);
			return (ft_strnew(0));
		}
		j = i;
		while (s[j] != '\0')
			j++;
		while (s[j - 1] == ' ' || s[j - 1] == '\t' || s[j - 1] == '\n')
			j--;
		j--;
		return (ft_strsubf(s, i, (j - i) + 1));
	}
	return (NULL);
}
