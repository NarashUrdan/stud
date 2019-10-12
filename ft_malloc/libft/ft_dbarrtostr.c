/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbarrtostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm<jukuntzm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:00:33 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/05/14 13:17:15 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dbarrtostr(char **dbarr, char c)
{
	int		i;
	char	*str;

	i = -1;
	str = ft_strnew(0);
	while (dbarr[++i] != NULL)
	{
		str = ft_strjoinfree(str, dbarr[i], 1);
		if (dbarr[i + 1] != NULL)
			str = ft_strinsert(str, c, ft_strlen(str));
	}
	return (str);
}
