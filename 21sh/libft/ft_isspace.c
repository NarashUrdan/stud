/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 01:49:14 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/13 01:52:56 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(char s)
{
	if (s == '\t' || s == '\n' || s == '\v' ||
		s == '\f' || s == '\r' || s == ' ')
		return (1);
	return (0);
}
