/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 08:13:53 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/01/25 03:53:59 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_tdir(char *path)
{
	int			i;
	struct stat	buf;

	i = 0;
	if ((stat(path, &buf)) == -1)
	{
		ft_error2(path);
		return (-1);
	}
	else
	{
		if (S_ISDIR(buf.st_mode))
			return (1);
	}
	return (0);
}

int		ft_nbarg(char **multipath)
{
	int	i;

	i = 0;
	while (multipath[i])
		i++;
	return (i);
}

char	**ft_tripath2(char **multipath, char **ndir, char **dir)
{
	int	j;
	int k;
	int i;

	j = -1;
	k = -1;
	i = 0;
	while (ndir[++k])
		multipath[i++] = ft_strdup(ndir[k]);
	while (dir[++j])
		multipath[i++] = ft_strdup(dir[j]);
	multipath[i] = NULL;
	return (multipath);
}

int		ft_tripath(char **multipath, t_ar *ar)
{
	char	**dir;
	char	**notdir;
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	i = -1;
	dir = (char **)malloc(sizeof(char *) * ft_nbarg(multipath) + 1);
	notdir = (char **)malloc(sizeof(char *) * ft_nbarg(multipath) + 1);
	while (multipath[++i])
	{
		if (ft_tdir(multipath[i]) == -1)
			ft_putendl(strerror(errno));
		else if (ft_tdir(multipath[i]) == 1)
			dir[j++] = ft_strdup(multipath[i]);
		else
			notdir[k++] = ft_strdup(multipath[i]);
	}
	dir[j] = NULL;
	notdir[k] = NULL;
	multipath = ft_tripath2(multipath, notdir, dir);
	ft_open(multipath, ar);
	return (0);
}
