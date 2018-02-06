/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 00:34:54 by jukuntzm          #+#    #+#             */
/*   Updated: 2017/11/19 18:14:04 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int nb)
{
	int				len;
	char			*str;
	unsigned int	nbr;
	int				neg;

	len = 0;
	neg = 1;
	if (nb < 0)
	{
		neg = -1;
		nb = -nb;
		len++;
	}
	nbr = nb;
	while (nb /= 10)
		len++;
	if (!(str = (char *)malloc(sizeof(char) * len + 2)))
		return (NULL);
	str[++len] = '\0';
	str[--len] = (nbr % 10) + 48;
	while (nbr /= 10)
		str[--len] = (nbr % 10) + 48;
	if (neg == -1)
		str[0] = '-';
	return (str);
}
