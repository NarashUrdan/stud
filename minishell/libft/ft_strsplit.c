/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 02:23:12 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/12 09:14:29 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(char *s, char c)
{
	int		i;
	int		len;
	char	*str;

	str = (char *)s;
	len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != '\0')
			len++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (len);
}

static int		len_w(char *s, int i, char c)
{
	int count;

	count = 0;
	while (s[i] != c && s[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		len;
	int		k;

	i = -1;
	k = 0;
	if (s == NULL ||
		!(tab = (char **)malloc(sizeof(char *) * (ft_len((char *)s, c) + 1))))
		return (NULL);
	while (++i < ft_len((char *)s, c))
	{
		j = -1;
		while (s[k] == c && s[k] != '\0')
			k++;
		len = len_w((char *)s, k, c);
		if (!(tab[i] = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (++j < len && s[k] != '\0')
			tab[i][j] = (char)s[k++];
		tab[i][j] = '\0';
	}
	tab[i] = NULL;
	return (tab);
}
