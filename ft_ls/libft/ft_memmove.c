/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 01:12:58 by jukuntzm          #+#    #+#             */
/*   Updated: 2017/11/11 23:50:56 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dst;
	char	*sr;

	dst = (char *)dest;
	sr = (char *)src;
	if (sr < dst)
	{
		while (n--)
			dst[n] = sr[n];
	}
	else
		ft_memcpy(dst, sr, n);
	return (dst);
}
