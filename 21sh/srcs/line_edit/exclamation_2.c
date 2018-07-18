/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exclamation_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegros <slegros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:07:56 by slegros           #+#    #+#             */
/*   Updated: 2018/05/08 17:18:38 by slegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_exclamsearchint(char *tmp)
{
	int		index;
	t_h		the;
	char	*res;
	int		i;

	index = ft_atoi(tmp);
	the = ft_history(0, NULL, 0);
	if (ft_toabs(index) >= ft_dbarrlen(the.hist) || index == 0)
	{
		ft_putstr_col_fd("21sh: Event not found: !", YEL, 2);
		ft_putendl_col_fd(tmp, YEL, 2);
		return (NULL);
	}
	if (index > 0)
		res = ft_strdup(the.hist[index - 1]);
	else
	{
		i = ft_dbarrlen(the.hist) - 1;
		index--;
		while (++index < 0)
			i--;
		res = ft_strdup(the.hist[i]);
	}
	return (res);
}

char	*ft_exclamsearchchar(char *tmp)
{
	t_h		the;
	int		i;
	char	*res;

	the = ft_history(0, NULL, 0);
	i = ft_dbarrlen(the.hist) - 1;
	res = NULL;
	while (i >= 0)
	{
		if (ft_strncmp(tmp, the.hist[i], ft_strlen(tmp)) == 0)
			return ((res = ft_strdup(the.hist[i])));
		i--;
	}
	ft_putstr_col_fd("21sh: Event not found: !", YEL, 2);
	ft_putendl_col_fd(tmp, YEL, 2);
	return (NULL);
}

char	*ft_excla_replace(char *str, char *new, int start, int end)
{
	char	*tmp;

	tmp = ft_strsub(str, end, ft_strlen(str) - end);
	str = ft_strsubf(str, 0, start);
	str = ft_strjoinfree(str, new, 1);
	str = ft_strjoinfree(str, tmp, 3);
	return (str);
}
