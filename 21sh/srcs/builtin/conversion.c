/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegros <slegros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:55:07 by slegros           #+#    #+#             */
/*   Updated: 2018/05/12 12:25:42 by slegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			ft_clean_cmd(t_cmd cmd)
{
	if (cmd.cmd != NULL)
		free(cmd.cmd);
	if (cmd.opt != NULL)
		free(cmd.opt);
	if (cmd.args != NULL)
		cmd.args = ft_dbarr_free(cmd.args);
}

static void		ft_conversion_2(t_cmd *cmd)
{
	if (ft_strlen(cmd->opt) == 0)
	{
		free(cmd->opt);
		cmd->opt = NULL;
	}
	if (ft_dbarrlen(cmd->args) == 0)
	{
		cmd->args = ft_dbarr_free(cmd->args);
		cmd->args = NULL;
	}
}

t_cmd			ft_conversion_cd(char **entry)
{
	t_cmd	c;
	int		i;
	int		j;

	c.cmd = ft_strdup(entry[0]);
	c.opt = ft_strnew(0);
	c.args = ft_dbarrnew(0);
	i = 0;
	while (entry[++i] != NULL)
	{
		if (entry[i][0] == '-' && ft_dbarrlen(c.args) == 0
			&& ft_strlen(entry[i]) != 1)
		{
			j = 0;
			while (entry[i][++j] != '\0')
			{
				if (ft_strichr(c.opt, entry[i][j]) == -1)
					c.opt = ft_strinsert(c.opt, entry[i][j], ft_strlen(c.opt));
			}
		}
		else
			c.args = ft_dbarr_add(c.args, entry[i]);
	}
	ft_conversion_2(&c);
	return (c);
}

t_cmd			ft_conversion(char **entry)
{
	t_cmd	c;
	int		i;
	int		j;

	c.cmd = ft_strdup(entry[0]);
	c.opt = ft_strnew(0);
	c.args = ft_dbarrnew(0);
	i = 0;
	while (entry[++i] != NULL)
	{
		if (entry[i][0] == '-' && ft_dbarrlen(c.args) == 0)
		{
			j = 0;
			while (entry[i][++j] != '\0')
			{
				if (ft_strichr(c.opt, entry[i][j]) == -1)
					c.opt = ft_strinsert(c.opt, entry[i][j], ft_strlen(c.opt));
			}
		}
		else
			c.args = ft_dbarr_add(c.args, entry[i]);
	}
	ft_conversion_2(&c);
	return (c);
}
