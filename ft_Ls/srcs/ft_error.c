/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 05:04:49 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/02 01:02:46 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_timer(char *path1, char *path2)
{
	struct stat	buf;
	struct stat	buf2;

	if ((stat(path1, &buf)) == -1)
	{
		ft_error2(path1);
		return (0);
	}
	if (stat(path2, &buf2) == -1)
	{
		ft_error2(path2);
		return (0);
	}
	if ((buf.st_mtime - buf2.st_mtime) < 0)
		return (0);
	else
		return (1);
}

char	**ft_time(char **p1, char **p2, int s1, int s2)
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
		if (ft_timer(p1[i], p2[j]) == 0)
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

char	**time_sort(char **path, int nb, int s1, int i)
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
	p1 = time_sort(p1, (nb / 2), 0, 0);
	p2 = time_sort(p2, (nb - (nb / 2)), 0, 0);
	ft_freedoublearray(path);
	path = ft_time(p1, p2, s1, (nb - s1));
	ft_freedoublearray(p1);
	ft_freedoublearray(p2);
	return (path);
}

void	ft_error2(char *str)
{
	ft_putstr("ft_ls : ");
	if (ft_strncmp(str, "./", 2) == 0)
		ft_putstr(str + 2);
	else
		ft_putstr(str);
	ft_putstr(": ");
}

void	ft_error(char *str, char arg)
{
	ft_putstr(str);
	write(1, &arg, 1);
	ft_putendl("\nusage: ft_ls [-Ralrt] [file ...]");
}
