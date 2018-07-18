/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegros <slegros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 09:12:51 by slegros           #+#    #+#             */
/*   Updated: 2018/05/14 14:57:27 by slegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int		ft_get_iaccess_norme(char *cmd)
{
	if (is_reg(cmd) == 1 && access(cmd, X_OK) != -1)
		return (-1);
	else
		return (-2);
}

int				ft_get_iaccess(char **path, char *cmd)
{
	char	*tmp;
	int		i;

	i = 0;
	if (path != NULL)
	{
		while (path[i] != NULL)
		{
			tmp = ft_strjoin(path[i], "/");
			tmp = ft_strjoinfree(tmp, cmd, 1);
			if (access(tmp, F_OK | X_OK) != -1)
			{
				ft_strdel(&tmp);
				return (i);
			}
			i++;
			free(tmp);
		}
	}
	if (access(cmd, F_OK) != -1)
		return (ft_get_iaccess_norme(cmd));
	return (-3);
}

char			*ft_get_elem(char **env, char *elem)
{
	char	*cont_elem;
	int		i;

	i = 0;
	cont_elem = NULL;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], elem, ft_strlen(elem)) == 0
			&& env[i][ft_strlen(elem)] == '=')
		{
			cont_elem = ft_strsub(env[i], ft_strlen(elem) + 1,
				ft_strlen(env[i]) - (ft_strlen(elem) + 1));
		}
		i++;
	}
	return (cont_elem);
}

int				ft_get_elemi(char **env, char *elem)
{
	int		i;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], elem, ft_strlen(elem)) == 0
			&& env[i][ft_strlen(elem)] == '=')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

char			*ft_get_entry(void)
{
	char	*tmp;

	ft_read_line(&tmp, ft_button_line(1, 1));
	tmp = ft_exclamation(tmp);
	if (ft_onlyspc(tmp) == 1)
	{
		ft_strdel(&tmp);
		return (NULL);
	}
	else
		return (tmp);
}
