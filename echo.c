/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 00:08:11 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/09 02:13:15 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_quote(char *str)
{
	char	*tmp;
	char	*tmp2;
	int		l;

	l = 0;
	tmp2 = NULL;
	while (1)
	{
		tmp = NULL;
		write (1, "quote> ", 8);
		get_next_line(0, &tmp);
		str = ft_strjoinfree(str, "/", 1);
		if (ft_strchr(tmp, 39) == NULL)
			str = ft_strjoinfree(str, tmp, 1);
		else
		{
			l = ft_strlen(tmp) - ft_strlen(ft_strchr(tmp, 39));
			tmp2 = ft_strsub(tmp, 0, l);
			str = ft_strjoinfree(str, tmp2, 3);
			free(tmp);
			return (str);
		}
		free(tmp);
	}
	free(tmp);
	return (str);
}

char	*ft_dquote(char *str)
{
	char	*tmp;
	char	*tmp2;
	int		l;

	l = 0;
	tmp2 = NULL;
	while (1)
	{
		tmp = NULL;
		write (1, "dquote> ", 9);
		get_next_line(0, &tmp);
		str = ft_strjoinfree(str, "/", 1);
		if (ft_strchr(tmp, 34) == NULL)
			str = ft_strjoinfree(str, tmp, 1);
		else
		{
			l = ft_strlen(tmp) - ft_strlen(ft_strchr(tmp, 34));
			tmp2 = ft_strsub(tmp, 0, l);
			str = ft_strjoinfree(str, tmp2, 3);
			free(tmp);
			return (str);
		}
		free(tmp);
	}
	free(tmp);
	return (str);
}

void	ft_printecho(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
		{
			while (str[i] &&  str[++i] != (char)c)
			{
				if (str[i] == '/')
				{
					write(1, "\n", 1);
					i++;
				}
				write(1, &str[i], 1);
			}
		}
		if (str[i])
			write(1, &str[i], 1);
		i++;
	}
}

int	ft_echo(char **tab)
{
	int		i;
	char	*str;
	char	*tmp;
	int		c;

	i = 1;
	str = ft_strnew(0);
	c = 0;
	while (tab[i])
	{
		str = ft_strjoinfree(str, tab[i], 1);
		i++;
	}
	if ((tmp = ft_strchr(str, 39)) != NULL)
	{
		if (strchr((tmp + 1), 39) == NULL)
			str = ft_quote(str);
		c = 39;
	}
	else if ((tmp = ft_strchr(str, 34)) != NULL)
	{
		if (strchr((tmp + 1), 34) == NULL)
			str = ft_dquote(str);
		c = 34;
	}
	ft_printecho(str, c);
	write(1, "\n", 1);
	return (0);
}
