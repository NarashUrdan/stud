/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitwhitespaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 01:45:30 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/13 01:46:44 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbwd(char *s)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (s[i] != '\0')
	{
		while (ft_isspace(s[i]) == 1 && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			nb++;
		while (s[i] != '\0' && ft_isspace(s[i]) != 1)
			i++;
	}
	return (nb);
}

static int	ft_wdsz(char *s, int k)
{
	int		i;

	i = 0;
	while (ft_isspace(s[k]) != 1 && s[k] != '\0')
	{
		i++;
		k++;
	}
	return (i);
}

char		**ft_splitwhitespaces(char const *s)
{
	int		i;
	int		j;
	int		k;
	int		size;
	char	**res;

	i = -1;
	k = 0;
	if (s == NULL ||
			!(res = (char **)malloc(sizeof(char *) * (ft_nbwd((char *)s) + 1))))
		return (NULL);
	while (++i < ft_nbwd((char *)s))
	{
		j = -1;
		while (ft_isspace(s[k]) == 1 && s[k] != '\0')
			k++;
		size = ft_wdsz((char *)s, k);
		if (!(res[i] = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		while (++j < size && s[k] != '\0')
			res[i][j] = (char)s[k++];
		res[i][j] = '\0';
	}
	res[i] = NULL;
	return (res);
}
