/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 23:57:11 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/02 05:16:01 by jukuntzm         ###   ########.fr       */
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
	npath = (char **)malloc(sizeof(char *) * (i + 1));
	while (--i >= 0)
	{
		npath[j] = ft_strdup(path[i]);
		free(path[i]);
		path[i] = NULL;
		j++;
	}
	free(path);
	path = NULL;
	npath[j] = NULL;
	return (npath);
}

void	ft_printlnk(char *name)
{
	char	buf[1024];
	int		i;

	i = readlink(name, buf, 1024);
	buf[i] = '\0';
	if (i != -1)
	{
		ft_putstr(" -> ");
		ft_putstr(buf);
	}
}

void	ft_arl2(struct stat buf)
{
	if (S_ISLNK(buf.st_mode))
		write(1, "l", 1);
	else
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
}

void	ft_merde(struct stat buf)
{
	struct passwd *uid;

	if ((uid = getpwuid(buf.st_uid)) == 0)
		ft_putnbr(buf.st_uid);
	else
		ft_putstr(uid->pw_name);
	write(1, " ", 1);
}

int		ft_arl(char *name, struct stat buf)
{
	char			*time;
	struct group	*grgid;

	ft_arl2(buf);
	ft_putnbr(buf.st_nlink);
	write(1, " ", 1);
	ft_merde(buf);
	if ((grgid = getgrgid(buf.st_gid)) == 0)
		ft_putnbr(buf.st_gid);
	else
		ft_putstr(grgid->gr_name);
	write(1, " ", 1);
	ft_putnbr(buf.st_size);
	write(1, " ", 1);
	time = ctime(&buf.st_mtime);
	time = ft_strsub(time, 3, ft_strlen(time) - 12);
	ft_putstr(time);
	free(time);
	write(1, " ", 1);
	ft_putstr(ft_strrchr(name, 47) + 1);
	if (S_ISLNK(buf.st_mode))
		ft_printlnk(name);
	write(1, "\n", 1);
	return (0);
}
