/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbarrprint_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:09:15 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/15 12:09:18 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dbarrprint_fd(char **dbarr, int fd)
{
	int		i;

	i = 0;
	while (dbarr[i] != NULL)
	{
		ft_putendl_fd(dbarr[i], fd);
		i++;
	}
}
