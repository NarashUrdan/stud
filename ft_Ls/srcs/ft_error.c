/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 05:04:49 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/01/25 04:32:38 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_kiwi(int i, char **multipath, t_ar *ar)
{
	if (ft_nbarg(multipath) > 1 || ar->re)
	{
		if (ft_tdir(multipath[i]) && (ft_strcmp(multipath[i], ".")))
		{
			write(1, "\n", 1);
			ft_putstr(multipath[i]);
			ft_putendl(":");
		}
	}
}

char	**ft_time(char **path)
{
	struct stat	buf;
	int			i;
	struct stat	buf2;
	char	*tmp;
	
	i = 1;
	while (path[i])
	{
		if ((stat(path[i - 1], &buf)) == -1 || stat(path[i], &buf2) == -1)
		{
			ft_error2(path[i]);
			return(NULL);
		}
		if ((buf.st_mtime - buf2.st_mtime) < 0)
		{
			tmp = ft_strdup(path[i]);
			//free(path[i]);
			path[i] = ft_strdup(path[i - 1]);
			//free(path[i - 1]);
			path[i - 1] = ft_strdup(tmp);
			i = 0;
		}
		i++;
	}
//	free(tmp);
	return (path);
}

char	**ft_att(char **path, t_ar *ar)
{
	path = ft_tpath(path);
	if (ar->t)
		path = ft_time(path);
	if (ar->r)
		path = ft_rev(path);
	return (path);
}

char	*ft_malloc(char *opath, char *path, char *str)
{
	char	*m;

	m = ft_strjoinfree(opath, str, 0);
	if (path == NULL)
	{
		m = ft_strjoinfree(m, "\\", 1);
		return (m);
	}
	path = ft_strjoinfree(path, "\\", 1);
	m = ft_strjoinfree(path, m, 3);
	return (m);
}

void	ft_error2(char *str)
{
	ft_putstr("ft_ls : ");
	ft_putstr(str);
	ft_putstr(": ");
	ft_putendl(strerror(errno));
}

void	ft_error(char *str, char arg)
{
	ft_putstr(str);
	write(1, &arg, 1);
	ft_putendl("\nusage: ft_ls [-Ralrt] [file ...]");
}
