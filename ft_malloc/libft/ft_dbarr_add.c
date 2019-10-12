/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbarr_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 20:48:07 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/04 20:48:10 by jukuntzm         ###   ########.fr       */
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
