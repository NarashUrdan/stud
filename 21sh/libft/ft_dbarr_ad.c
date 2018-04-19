/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbarr_ad.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:05:43 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/04/18 17:16:12 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_dbarr_add(char **array, char *content)
{
	int		len;
	char	**array2;
	int		i;

	i = 0;
	len = ft_dbarrlen(array) + 1;
	if (!(array2 = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (array[i] != NULL)
	{
		array2[i] = ft_strdup(array[i]);
		i++;
	}
	array2[i] = ft_strdup(content);
	i++;
	array2[i] = NULL;
	i = -1;
	while (array[++i] != NULL)
		free(array[i]);
	free(array);
	return (array2);
}
