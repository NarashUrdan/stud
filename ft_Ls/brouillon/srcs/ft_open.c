/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 21:59:50 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/01/24 02:33:31 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	ft_arl(char *path, t_lst *files)
{
	ft_putstr((S_ISDIR(files->buf.st_mode)) ? "d" : "-");
	ft_putstr((files->buf.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((files->buf.st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr((files->buf.st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr((files->buf.st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((files->buf.st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr((files->buf.st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr((files->buf.st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((files->buf.st_mode & S_IWOTH) ? "w" : "-");
	ft_putstr((files->buf.st_mode & S_IXOTH) ? "x" : "-");
	write(1," ", 1);
	ft_putnbr(files->buf.st_nlink);
	write(1," ", 1);
	files->uid = getpwuid(files->buf.st_uid);
	files->grgid = getgrgid(files->buf.st_gid);
	ft_putstr(files->uid->pw_name);
	write(1," ", 1);
	ft_putstr(files->grgid->gr_name);
	write(1," ", 1);
	ft_putnbr(files->buf.st_size);
	write(1," ", 1);
	files->time = ctime(&files->buf.st_mtime);
	files->time = ft_strsub(files->time, 3, ft_strlen(files->time) - 12);
	ft_putstr(files->time);
	write(1," ", 1);
	ft_putendl(path);
	return (0);

}

void	ft_npath(char *path)
{
	ft_putstr(path);
	ft_putstr(" :\n");
}

char	**ft_ascii(char **path)
{
	int		i;
	char	*tmp;

	i = 1;
	while (path[i])
	{
		if (ft_strcmp(path[i - 1], path[i]) > 0)
		{
			tmp = ft_strdup(path[i - 1]);
			free(path[i - 1]);
			path[i] = ft_strdup(path[i]);
			free(path[i]);
			path[i] = ft_strdup(tmp);
			i = 0;
		}
		i++;
	}
	return (path);
}

int	ft_open(char **path, t_ar ar)
{
	t_lst			*files;
	int				i;
	int				j;
	int				l;

	j = 0;
	l = 0;
	path = ft_ascii(path);
	i = (ar.a) ? 0 : 2;
	while (path[j])
	{
		files = ft_memalloc(sizeof(files));
		ft_getinfo(path[j], files, ar);
		write(1, "s", 1);
		if (ar.t)
			ft_time(files);
/*		if (ar.r)
			ft_rev(files);*/
		if (ar.l)
		{
			ft_arl(path[j], files);
			while (files->next)
			{
				ft_arl(path[j], files);
				files = files->next;
			}
		}
		j++;
	}
	return (0);
}
