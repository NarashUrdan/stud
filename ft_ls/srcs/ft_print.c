/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 21:20:57 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/03 13:03:29 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	**ft_newpath(char **path, t_ar *ar)
{
	int		i;
	int		j;
	char	**multipath;

	j = 0;
	i = 0;
	if (!(multipath = (char **)malloc(sizeof(char *) * (ft_nbarg(path) + 1))))
		return (NULL);
	while (path[i])
	{
		if (ft_strnstr(path[i], "/.", ft_strlen(path[i])))
			i++;
		else if ((ft_tdir(path[i]) == 1 &&
				ft_strnstr(path[i], "..", ft_strlen(path[i])) == NULL) ||
				(ft_tdir(path[i]) == 2 && !ar->l && !ar->re))
			multipath[j++] = ft_strdup(path[i++]);
		else
			i++;
	}
	ft_freedoublearray(path);
	multipath[j] = NULL;
	return (multipath);
}

int		ft_print(char **path, t_ar *ar)
{
	struct stat buf;
	int			i;

	i = 0;
	if (path == NULL)
		return (0);
	while (path[i])
	{
		if (ar->l)
		{
			if (ft_ifar(path[i], &buf))
				return (-1);
		}
		else
		{
			if (ft_nar(path[i], &buf))
				return (-1);
		}
		i++;
	}
	path = ft_tropdeligne(path, ar);
	return (0);
}

int		ft_opendir(char *path, t_ar *ar)
{
	DIR				*dir;
	struct dirent	*inf;
	char			*npath;

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
				npath = ft_malloc(npath, inf->d_name);
		}
		else
			npath = ft_malloc(npath, inf->d_name);
	}
	closedir(dir);
	ft_29lignes(path, npath, ar);
	free(npath);
	return (0);
}

char	*readlk(char *path)
{
	char	*buf;
	int		j;
	char	*tmp;
	int		i;

	buf = (char *)malloc(sizeof(char) * (1023));
	i = ft_strlen(path) - ft_strlen(ft_strrchr(path, '/')) + 1;
	j = readlink(path, buf, 1023);
	buf[j] = '\0';
	tmp = ft_strsub(path, 0, i);
	tmp = ft_strjoinfree(tmp, buf, 1);
	tmp = ft_strjoinfree(tmp, "/", 1);
	free(buf);
	return (tmp);
}

int		ft_open(char **multipath, t_ar *ar)
{
	int		i;

	i = 0;
	if (multipath[0] == NULL)
	{
		ft_freedoublearray(multipath);
		return (0);
	}
	multipath = ft_att(multipath, ar);
	if (ar->r)
		multipath = ft_tripath(multipath, ar, -1, 0);
	while (multipath[i])
	{
		ft_kiwi(i, multipath, ar);
		multipath[i] = ft_checkp(multipath[i]);
		if (ft_tdir(multipath[i]) == 2 && !ar->l && !ar->re)
			lk(multipath[i], ar);
		else if (ft_tdir(multipath[i]) == 0 || ft_tdir(multipath[i]) == 2)
			files(multipath[i], ar);
		else
			ft_opendir(multipath[i], ar);
		i++;
	}
	ft_freedoublearray(multipath);
	return (0);
}
