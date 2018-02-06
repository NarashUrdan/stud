/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 13:04:05 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/03 13:40:47 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	lk(char *path, t_ar *ar)
{
	char	*lnk;

	lnk = readlk(path);
	ft_opendir(lnk, ar);
	free(lnk);
}

void	files(char *path, t_ar *ar)
{
	char	**merde;

	merde = ft_strsplit(path, '\0');
	ft_print(merde, ar);
	ft_freedoublearray(merde);
}

char	*ft_malloc(char *path, char *str)
{
	if (path == NULL)
		path = ft_strdup(str);
	else
		path = ft_strjoinfree(path, str, 1);
	path = ft_strjoinfree(path, "/", 1);
	return (path);
}

void	ft_kiwi(int i, char **multipath, t_ar *ar)
{
	if (ft_nbarg(multipath) > 1 || ar->re)
	{
		if (ft_tdir(multipath[i]) > 0 && (ft_strcmp(multipath[i], ".")))
		{
			if ((ar->re || i != 0) && (ft_tdir(multipath[i]) == 1 ||
				(ft_tdir(multipath[i]) == 2 && !ar->l)))
				write(1, "\n", 1);
			if (ar->re)
				ft_putstr(multipath[i]);
			else
				ft_putstr(ft_strchr(multipath[i], '/') + 1);
			ft_putendl(":");
		}
	}
}
