/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 21:20:57 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/01/25 04:32:40 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*ft_checkp(char *path)
{
	int	i;

	i = ft_strlen(path);
	if (path[i] != '/')
		path = ft_strjoinfree(path, "/", 1);
	return (path);
}

char	**ft_newpath(char **path)
{
	int 	i;
	int		j;
	char	**multipath;

	j = 0;
	i = 1;
	if (!(multipath = (char **)malloc(sizeof(char *) * ft_nbarg(path) + 1)))
		return (NULL);
	while (path[i])
	{
		if (ft_tdir(path[i]))
			multipath[j++] = ft_strdup(path[i]);
		i++;
	}
	free(path);
	multipath[j] = NULL;
	return (multipath);
}
int		ft_print(char **path, t_ar *ar)
{
	struct stat buf;
	int			i;

	i = 0;
	path = ft_att(path, ar);
	while (path[i])
	{
		if ((lstat(path[i], &buf)) == -1)
		{
			ft_error2(path[i]);
			return (-1);
		}
		if (ar->l)
			ft_arl(path[i], buf);
		else
			ft_putendl(ft_strrchr(path[i], 47));
		i++;
	}
	if (ar->re)
	{
		path = ft_newpath(path);
		ft_open(path, ar);
	}
	return (0);
}

int		ft_opendir(char *path, t_ar *ar)
{
	DIR				*dir;
	struct dirent	*inf;
	int				i;
	char			*npath;

	i = 0;
	npath = NULL;
	if (!(dir = opendir(path)))
	{
		ft_error2(path);
		ft_putendl(strerror(errno));
		return (0);
	}
	while ((inf = readdir(dir)) != NULL)
	{
			if (ar->a == 0)
			{
				if (ft_strncmp(inf->d_name, ".", 1) != 0)
					npath = ft_malloc(path, npath, inf->d_name);
			}
			else
				npath = ft_malloc(path, npath, inf->d_name);
	}
	closedir(dir);
	ft_print(ft_strsplit(npath, 92), ar);
	return (0);
}

int		ft_open(char **multipath, t_ar *ar)
{
	int	i;

	i = 0;
	if (multipath[0] == NULL)
		return (0);
	while (multipath[i])
	{
		ft_kiwi(i, multipath, ar);
		multipath[i] = ft_checkp(multipath[i]);
		if (ft_tdir(multipath[i]) == 0)
			ft_print(&multipath[i], ar);
		else
			ft_opendir(multipath[i], ar);
		i++;
	}
	return (0);
}
