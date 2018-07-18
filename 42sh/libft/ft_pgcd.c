/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pgcd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 07:52:07 by slegros           #+#    #+#             */
/*   Updated: 2017/12/22 07:53:13 by slegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pgcd(int a, int b)
{
	int		i;
	int		res;

	i = 1;
	res = 1;
	while (i <= a && i <= b)
	{
		if (a % i == 0 && b % i == 0)
			res = i;
		i++;
	}
	return (res);
}
