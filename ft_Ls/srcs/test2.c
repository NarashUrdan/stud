/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 22:39:34 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/01/16 05:46:34 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_ls.h"

int ft_l(struct t_lst *lst, struct dirent *zob)
{
	struct stat buf;

	if (stat(zob->d_name, &buf) == -1)
		ft_putstr(strerror(errno));
	ft_putstr((S_ISDIR(buf.st_mode)) ? "d" : "-");
	ft_putstr((lst->buf.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((buf.st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr((buf.st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr((buf.st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((buf.st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr((buf.st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr((buf.st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((buf.st_mode & S_IWOTH) ? "w" : "-");
	ft_putstr((buf.st_mode & S_IXOTH) ? "x" : "-");
	write(1," ", 1);
	ft_putnbr(buf.st_nlink);
	write(1," ", 1);
	lst->uid = getpwuid(buf.st_uid);
	lst->bite = getgrgid(buf.st_gid);
	ft_putstr(lst->uid->pw_name);
	write(1," ", 1);
	ft_putstr(lst->bite->gr_name);
	write(1," ", 1);
	ft_putnbr(buf.st_size);
	write(1," ", 1);
	lst->merde = ctime(&buf.st_ctime);
	lst->merde = ft_strsub(lst->merde, 3, ft_strlen(lst->merde) - 12);
	ft_putstr(lst->merde);
	write(1," ", 1);
	ft_putendl(zob->d_name);
	return (0);
}
