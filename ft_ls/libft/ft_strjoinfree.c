/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 02:31:05 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/03 12:45:33 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2, int m)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	if (m == 1 || m == 3)
		free(s1);
	if (m == 2 || m == 3)
		free(s2);
	return (str);
}
