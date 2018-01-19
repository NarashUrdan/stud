/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:46:27 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/01/19 04:18:21 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	ft_dirornotdir(char *path)
{
	struct stat sta;

	if (stat(path, &sta) == -1)
	{
		ft_putstr(strerror(errno));
		return (-1);
	}
	return (S_ISDIR(sta.st_mode) ? 1 : 0);
}

int	ft_getminfo(char *path, t_lst *files)
{
	stat(path, &files->buf);
	files->uid = getpwuid(files->buf.st_uid);
	files->grgid = getgrgid(files->buf.st_gid);
	files->time = ctime(&files->buf.st_mtime);
	files->dor = (S_ISDIR(files->buf.st_mode)) ? 1 : 0;
	return (0);
}

int	ft_getinfo(char *path, t_lst *files, t_ar ar)
{
	int	i;
	DIR	*op;
	struct stat sb;

	i = (ar.a) ? 0 : 2;
	ft_putstr("bite\n");
	if ((lstat(".", &files->buf)) == -1)
	{	
		perror("");
		return (0);
	}
	ft_putstr("bite\n");
	files->dor = (S_ISDIR(sb.st_mode)) ? 1 : 0;
	printf("sb->d_name ===> %d\n", files->dor);
	if (files->dor == 1)
	{
		if (!(op = opendir(path)))
	   		ft_putstr(strerror(errno));
		while ((files->dir = readdir(op)))
		{
			if (i > 0)
				i--;
			else
			{
				ft_getminfo(path, files);
				files = files->next;
			}
		}
	}
	else
		ft_getminfo(path, files);
	return (0);
}
/*
int	ft_dir(char *path, t_lst files)
{
	DIR		*op;

	if (!(op = opendir(path)))
	   ft_putstr(strerror(errno));
	if ((files.dir = readdir(op)) == NULL)
		ft_putstr(strerror(errno));
}

int	ft_rev(t_lst files)
{
	t_lst	rev;
	
}
*/
int ft_time(t_lst *files)
{
	t_lst *tmp;
	while (files->next)
	{
		if (ft_strcmp(files->time, files->next->time) > 0)
		{
			tmp = files;
			files = files->next;
			files->next = tmp;
		}
	}
	return (0);
}
