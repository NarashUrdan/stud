/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 23:57:11 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/01/25 04:32:36 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	**ft_rev(char **path)
{
	char	**npath;
	int		i;
	int		j;

	i = ft_nbarg(path);
	j = 0;
	npath = (char **)malloc(sizeof(char *) * i + 1);
	while(--i >= 0)
	{
		npath[j] = ft_strdup(path[i]);
		free(path[i]);
		j++;
	}
	free(path);
	npath[j] = NULL;
	return (npath);
}

int		ft_arl(char *name, struct stat buf)
{
	char	*time;
	struct passwd	*uid;
	struct group	*grgid;

	ft_putstr((S_ISDIR(buf.st_mode)) ? "d" : "-");
	ft_putstr((buf.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((buf.st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr((buf.st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr((buf.st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((buf.st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr((buf.st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr((buf.st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((buf.st_mode & S_IWOTH) ? "w" : "-");
	ft_putstr((buf.st_mode & S_IXOTH) ? "x" : "-");
	write(1, " ", 1);
	ft_putnbr(buf.st_nlink);
	write(1," ", 1);
	uid = getpwuid(buf.st_uid);
	grgid = getgrgid(buf.st_gid);
	ft_putstr(uid->pw_name);
	write(1," ", 1);
	ft_putstr(grgid->gr_name);
	write(1," ", 1);
	ft_putnbr(buf.st_size);
	write(1," ", 1);
	time = ctime(&buf.st_mtime);
	time = ft_strsub(time, 3, ft_strlen(time) - 12);
	ft_putstr(time);
	write(1," ", 1);
	ft_putendl(ft_strrchr(name, 47) + 1);
	return (0);
}
