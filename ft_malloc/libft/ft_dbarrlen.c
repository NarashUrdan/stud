/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbarrlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 20:48:58 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/04 20:48:58 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dbarrlen(char **dbarr)
{
	int		i;

	i = 0;
	while (dbarr[i] != NULL)
		i++;
	return (i);
}
