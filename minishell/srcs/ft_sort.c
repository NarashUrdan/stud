/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 07:08:06 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/09 09:01:55 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**merge(char **p1, char **p2, int s1, int s2)
{
	char	**merges;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	merges = (char **)malloc(sizeof(char *) * (s1 + s2 + 1));
	while (i < s1 && j < s2)
	{
		if (ft_strcmp(p1[i], p2[j]) < 0)
			merges[k++] = ft_strdup(p2[j++]);
		else
			merges[k++] = ft_strdup(p1[i++]);
	}
	while (i < s1)
		merges[k++] = ft_strdup(p1[i++]);
	while (j < s2)
		merges[k++] = ft_strdup(p2[j++]);
	merges[k] = NULL;
	return (merges);
}

char	**merge_sort(char **path, int nb, int s1, int i)
{
	char	**p1;
	char	**p2;

	if (nb < 2)
		return (path);
	s1 = nb / 2;
	p1 = (char **)malloc(sizeof(char *) * (s1 + 1));
	p2 = (char **)malloc(sizeof(char *) * ((nb - s1) + 1));
	i = -1;
	while (++i < s1)
		p1[i] = ft_strdup(path[i]);
	p1[i] = NULL;
	i = (nb / 2) - 1;
	s1 = 0;
	while (++i < nb)
		p2[s1++] = ft_strdup(path[i]);
	p2[s1] = NULL;
	s1 = nb / 2;
	p1 = merge_sort(p1, (nb / 2), 0, 0);
	p2 = merge_sort(p2, (nb - (nb / 2)), 0, 0);
	ft_freedoublearray(path);
	path = merge(p1, p2, s1, (nb - s1));
	ft_freedoublearray(p1);
	ft_freedoublearray(p2);
	return (path);
}
