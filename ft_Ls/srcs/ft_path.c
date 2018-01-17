/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 22:56:07 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/01/15 23:25:34 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	ft_path(char *ar)
{
	DIR	*fd;
	 s_lst *lst;
	struct dirent *zob;

	ar = NULL;
	fd = opendir(".");
	lst = NULL;
	while ((zob = readdir(fd)))
	{
		ft_l(lst, zob);
		lst = lst->next;
	}
	return (0);
}
