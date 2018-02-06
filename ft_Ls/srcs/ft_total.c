/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_total.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 03:03:13 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/03 12:42:20 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	**ft_tropdeligne(char **path, t_ar *ar)
{
	if (ar->re)
	{
		path = ft_newpath(path, ar);
		ft_open(path, ar);
	}
	return (path);
}

void	ft_29lignes(char *opath, char *npath, t_ar *ar)
{
	char			**multipath;
	int				i;

	i = -1;
	if (npath == NULL)
		return ;
	multipath = ft_strsplit(npath, '/');
	if (ar->l)
		ft_total(multipath, opath, ar);
	else
	{
		while (multipath[++i])
			multipath[i] = ft_strjoinfree(opath, multipath[i], 2);
	}
	multipath = ft_att(multipath, ar);
	ft_print(multipath, ar);
	if (!ar->re)
		ft_freedoublearray(multipath);
}

char	**ft_att(char **path, t_ar *ar)
{
	path = merge_sort(path, ft_nbarg(path), 0, 0);
	path = ft_rev(path);
	if (ar->t)
		path = time_sort(path, ft_nbarg(path), 0, 0);
	if (ar->r)
		path = ft_rev(path);
	return (path);
}

int		ft_total_noleaks(char *path)
{
	struct stat		buf;

	lstat(path, &buf);
	return ((int)buf.st_blocks);
}

void	ft_total(char **multipath, char *opath, t_ar *ar)
{
	int		i;
	int		total;

	i = 0;
	total = 0;
	if (ar->l)
	{
		while (multipath[i] != NULL)
		{
			multipath[i] = ft_strjoinfree(opath, multipath[i], 2);
			if (ar->a == 1 && multipath[i][2] == '.')
				i++;
			else
			{
				total += ft_total_noleaks(multipath[i]);
				i++;
			}
		}
		ft_putstr("total ");
		ft_putnbr(total);
		ft_putchar('\n');
	}
}
