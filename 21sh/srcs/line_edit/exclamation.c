/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exclamation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegros <slegros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 18:33:17 by slegros           #+#    #+#             */
/*   Updated: 2018/05/08 17:24:18 by slegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int		ft_get_word(char *str, int start, int *mode)
{
	int		j;

	j = start + 1;
	if (ft_isdigit(str[j]) == 1 || (str[j] == '-'
		&& ft_isdigit(str[j + 1]) == 1))
	{
		if (str[j] == '-')
			j++;
		while (str[j] != '\0' && (ft_isdigit(str[j]) == 1))
			j++;
		*mode = 1;
	}
	else
	{
		while (str[j] != '\0' && ft_isspace(str[j]) == 0
			&& ft_isop(str[j]) == 1 && ft_issep(str[j]) == 0 && str[j] != '!')
			j++;
		*mode = 2;
	}
	return (j);
}

static char		*ft_exclam_str(char *str, int start, int *ok)
{
	char	*tmp;
	int		j;
	int		mode;
	char	*tmp2;

	j = ft_get_word(str, start, &mode);
	if (j - (start + 1) > 0)
	{
		tmp = ft_strsub(str, start + 1, j - (start + 1));
		tmp2 = (mode == 1) ? ft_exclamsearchint(tmp) : ft_exclamsearchchar(tmp);
		free(tmp);
		if (tmp2 != NULL)
		{
			*ok = 1;
			str = ft_excla_replace(str, tmp2, start, j);
			free(tmp2);
		}
		else
			str[0] = '\0';
	}
	else
		str = ft_strrem(str, start);
	return (str);
}

char			*ft_exclamation(char *str)
{
	int		i;
	int		ok;

	i = -1;
	ok = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == '!' && ft_inbrk(str, i) == 0)
			str = ft_exclam_str(str, i, &ok);
		if (str[0] == '\0')
		{
			ok = 0;
			ft_history(20, NULL, 0);
			break ;
		}
	}
	if (ok == 1)
	{
		ft_history(21, str, 0);
		ft_putendl_fd(str, 0);
	}
	return (str);
}
