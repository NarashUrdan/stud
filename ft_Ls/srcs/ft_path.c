/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 21:39:24 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/01/25 03:36:10 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	**ft_tpath(char **multipath)
{
	int		i;
	char	*tmp;

	i = 1;
	while (multipath[i])
	{
		if (ft_strcmp(multipath[i - 1], multipath[i]) > 0)
		{
			tmp = ft_strdup(multipath[i - 1]);
			free(multipath[i - 1]);
			multipath[i - 1] = ft_strdup(multipath[i]);
			free(multipath[i]);
			multipath[i] = ft_strdup(tmp);
			free(tmp);
			i = 0;
		}
		i++;
	}
	return (multipath);
}

char	**ft_multipath(char **arg, char **multipath, int i)
{
	int	j;
	int	tmp;
	int	l;

	tmp = i;
	while (arg[tmp])
		tmp++;
	if (!(multipath = (char **)malloc(sizeof(char *) * tmp + 1)))
		return (NULL);
	tmp = 0;
	while (arg[i])
	{
		l = ft_strlen(arg[i]);
		if (!(multipath[tmp] = (char *)malloc(sizeof(char) * l + 1)))
			return (NULL);
		j = -1;
		while (arg[i][++j])
			multipath[tmp][j] = arg[i][j];
		multipath[tmp++][j] = '\0';
		i++;
	}
	multipath[tmp] = NULL;
	return (ft_tpath(multipath));
}

int		ft_path(char **arg, char **multipath, int i, t_ar *ar)
{
	if (arg[i] == NULL)
	{
		multipath = (char **)malloc(sizeof(char) * 1);
		multipath[0] = ft_strdup(".");
		multipath[1] = NULL;
	}
	else
	{
		if ((multipath = ft_multipath(arg, multipath, i)) == NULL)
			return (1);
	}
	ft_tripath(multipath, ar);
	return (0);
}
