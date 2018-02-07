/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 03:18:42 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/07 01:08:14 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int		merde(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

void	ft_28lignes(char **str, char **line)
{
	int		i;
	char	*tmp;

	i = merde(*str);
	*line = ft_strsub(*str, 0, i);
	tmp = ft_strsub(*str, (i + 1), (ft_strlen(*str) - i));
	free(*str);
	*str = ft_strdup(tmp);
	free(tmp);
}

int		get_next_line(int fd, char **line)
{
	static char		*str;
	int				ret;
	char			tmp2[BUFF_SIZE + 1];

	if (!line || fd < 0)
		return (-1);
	ret = 1;
	str = (str == NULL) ? ft_strnew(0) : str;
	while (!(ft_strchr(str, '\n')) && ret > 0)
	{
		ft_bzero(tmp2, BUFF_SIZE + 1);
		ret = read(fd, tmp2, BUFF_SIZE);
		str = ft_strjoinfree(str, tmp2, 1);
		if (ret == 0 && str[0] == '\0')
			return (0);
		if (ret == 0)
			break ;
		if (ret < 0)
			return (-1);
	}
	ft_28lignes(&str, line);
	return (1);
}
