/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 22:56:07 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/01/17 22:46:44 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*ft_path(char *path)
{
	char	*nwpath;
	int		i;

	i = 0;
	nwpath = ft_strnew(2);
	nwpath = ft_strdup("./");
	if ((ft_strcmp(path, ".")) != 0)
		nwpath = ft_strjoinfree(nwpath, path, 3);
	nwpath = ft_strjoinfree(nwpath, "/", 1);
	return (nwpath);
}
