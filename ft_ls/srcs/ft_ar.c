/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 08:13:53 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/03 14:03:01 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_tdir(char *path)
{
	struct stat	buf;

	if (lstat(path, &buf) == -1)
	{
		ft_error2(path);
		return (-1);
	}
	else
	{
		if (S_ISLNK(buf.st_mode))
			return (2);
		else if (S_ISDIR(buf.st_mode))
			return (1);
	}
	return (0);
}

int		ft_nbarg(char **multipath)
{
	int	i;

	i = 0;
	if (!multipath)
		return (0);
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
	{
		free(multipath[i]);
		multipath[i++] = ft_strdup(ndir[k]);
	}
	while (dir[++j])
	{
		free(multipath[i]);
		multipath[i++] = ft_strdup(dir[j]);
	}
	ft_freedoublearray(ndir);
	ft_freedoublearray(dir);
	multipath[i] = NULL;
	return (multipath);
}

char	*ft_onenagros(char *multipath)
{
	if (ft_strncmp(multipath, ".", 1) != 0 &&
		ft_strncmp(multipath, "/", 1) != 0)
		multipath = ft_strjoinfree("./", multipath, 2);
	return (multipath);
}

char	**ft_tripath(char **multipath, t_ar *ar, int i, int j)
{
	char	**dir;
	char	**notdir;
	int		k;
	int		l;

	k = 0;
	dir = (char **)malloc(sizeof(char *) * (ft_nbarg(multipath) + 1));
	notdir = (char **)malloc(sizeof(char *) * (ft_nbarg(multipath) + 1));
	while (multipath[++i])
	{
		l = ft_tdir(multipath[i]);
		multipath[i] = ft_onenagros(multipath[i]);
		if (l == 2 && ar->l)
			notdir[k++] = ft_strdup(multipath[i]);
		else if (l == 1 || l == 2)
			dir[j++] = ft_strdup(multipath[i]);
		else if (l == 0)
			notdir[k++] = ft_strdup(multipath[i]);
	}
	dir[j] = NULL;
	notdir[k] = NULL;
	multipath = ft_tripath2(multipath, notdir, dir);
	return (multipath);
}
