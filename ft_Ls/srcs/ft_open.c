/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 21:59:50 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/01/17 05:26:23 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	ft_arl(char *path, t_lst files)
{
	if (stat(path, &(files.buf)) == -1)
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
	files.bite = getgrgid(files.buf.st_gid);
	ft_putstr(files.uid->pw_name);
	write(1," ", 1);
	ft_putstr(files.bite->gr_name);
	write(1," ", 1);
	ft_putnbr(files.buf.st_size);
	write(1," ", 1);
	files.merde = ctime(&files.buf.st_mtime);
	files.merde = ft_strsub(files.merde, 3, ft_strlen(files.merde) - 12);
	ft_putstr(files.merde);
	write(1," ", 1);
	ft_putendl(files.dir->d_name);
	return (0);

}

int	ft_open(char *path, t_ar ar)
{
	DIR				*op;
	t_lst	files;
	int				i;

	i = (ar.a == 1) ? 0 : 2;
	op = opendir(path);
	while ((files.dir = readdir(op)))
	{
		if (i > 0)
			i--;
		else
		{
			if (ar.l == 1)
				ft_arl(files.dir->d_name, files);
			else	
			ft_putendl(files.dir->d_name);
		}
	}
	return (0);
}
