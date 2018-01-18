/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 21:59:50 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/01/18 05:28:41 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	ft_arl(char *path, t_lst files)
{
	char *str;

	str = ft_strdup(path);
	str = ft_strjoinfree(str, "/", 1);
	str = ft_strjoinfree(str, files.dir->d_name, 1);
	if ((stat(str, &(files.buf))) == -1)
		ft_putstr(strerror(errno));
	ft_putstr((S_ISDIR(files.buf.st_mode)) ? "d" : "-");
	ft_putstr((files.buf.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((files.buf.st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr((files.buf.st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr((files.buf.st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((files.buf.st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr((files.buf.st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr((files.buf.st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((files.buf.st_mode & S_IWOTH) ? "w" : "-");
	ft_putstr((files.buf.st_mode & S_IXOTH) ? "x" : "-");
	write(1," ", 1);
	ft_putnbr(files.buf.st_nlink);
	write(1," ", 1);
	files.uid = getpwuid(files.buf.st_uid);
	files.grgid = getgrgid(files.buf.st_gid);
	ft_putstr(files.uid->pw_name);
	write(1," ", 1);
	ft_putstr(files.grgid->gr_name);
	write(1," ", 1);
	ft_putnbr(files.buf.st_size);
	write(1," ", 1);
	files.time = ctime(&files.buf.st_mtime);
	files.time = ft_strsub(files.time, 3, ft_strlen(files.time) - 12);
	ft_putstr(files.time);
	write(1," ", 1);
	ft_putendl(files.dir->d_name);
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
	DIR				*op;
	t_lst			files;
	int				i;
	int				j;
	int				l;

	j = 0;
	l = 0;
	path = ft_ascii(path);
	while (path[l])
		l++;
	while (path[j])
	{
		i = (ar.a == 1) ? 0 : 2;
		if (!(op = opendir(path[j])))
		{
			ft_putstr("ft_ls : ");
			ft_putstr(path[j]);
			ft_putstr(": ");
			ft_putstr(strerror(errno));
		}
		else
		{
			if (l != 1)
				ft_npath(path[j]);
			while ((files.dir = readdir(op)))
			{
				if (i > 0)
					i--;
				else
				{
					if (ft_arl(path[j], files))
						return (1);
				}
			}
		}
		j++;
		i = 0;
		if (l != 1 && path[j] != NULL)
			write (1, "\n", 1);
	}
	return (0);
}
