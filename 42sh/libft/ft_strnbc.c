/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnbc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:06:32 by slegros           #+#    #+#             */
/*   Updated: 2018/02/15 12:06:33 by slegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnbc(char *str, char c)
{
	int		i;
	int		estin;

	i = 0;
	estin = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			estin++;
		i++;
	}
	return (estin);
}
