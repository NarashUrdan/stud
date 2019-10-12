/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbarr_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm<jukuntzm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:09:02 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/04/21 18:09:20 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_dbarr_free(char **array)
{
	int		i;

	i = -1;
	while (array[++i] != NULL)
		free(array[i]);
	free(array);
	return (array);
}
