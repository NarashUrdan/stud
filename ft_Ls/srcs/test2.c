/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 22:39:34 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/01/15 05:30:57 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_ls.h"

int ft_l(struct t_lst *lst, struct dirent *zob)
{
	ft_putstr(zob->d_name);
	if (stat(zob->d_name, &lst->buf) == -1)
		ft_putstr(strerror(errno));
	ft_putnbr(lst->buf.st_size);
	write(1, "d", 1);
	ft_putstr((S_ISDIR(lst->buf.st_mode)) ? "d" : "-");
	ft_putstr((lst->buf.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((lst->buf.st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr((lst->buf.st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr((lst->buf.st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((lst->buf.st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr((lst->buf.st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr((lst->buf.st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((lst->buf.st_mode & S_IWOTH) ? "w" : "-");
	ft_putstr((lst->buf.st_mode & S_IXOTH) ? "x" : "-");
	ft_putstr(" ");
	ft_putnbr(lst->buf.st_nlink);
	write(1," ", 1);
	 lst->uid = getpwuid(lst->buf.st_uid);
	 lst->bite = getgrgid(lst->buf.st_gid);
	ft_putstr(lst->uid->pw_name);
	write(1," ", 1);
	ft_putstr(lst->bite->gr_name);
	write(1," ", 1);
	ft_putnbr(lst->buf.st_size);
	write(1," ", 1);
	lst->merde = ctime(&lst->buf.st_ctime);
	lst->merde = ft_strsub(lst->merde, 3, ft_strlen(lst->merde) - 12);
	ft_putstr(lst->merde);
	write(1," ", 1);
	ft_putstr(zob->d_name);
	write(1,"\n", 1);
	return (0);
}
