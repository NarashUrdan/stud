/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegros <slegros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 09:14:01 by slegros           #+#    #+#             */
/*   Updated: 2018/05/08 17:03:40 by slegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		is_reg(char *file)
{
	struct stat		infos;

	if (lstat(file, &infos) != -1 && S_ISREG(infos.st_mode))
		return (1);
	else
		return (0);
}

int		ft_check_name(char *name)
{
	int		i;

	if (ft_isalpha(name[0]) == 0 && name[0] != '_')
		return (-1);
	i = 1;
	while (name[i] != '\0')
	{
		if (ft_isalpha(name[i]) == 0
			&& ft_isdigit(name[i]) == 0 && name[i] != '_')
		{
			return (-1);
		}
		i++;
	}
	return (1);
}

char	**ft_change_pwd(char **env, char *new_pwd)
{
	char	*tmp;
	char	*tmp_new;
	int		ipwd;
	int		iold;
	char	**new_env;

	tmp_new = ft_strjoin("PWD=", new_pwd);
	if ((iold = ft_get_elemi(env, "OLDPWD")) != -1)
	{
		if ((ipwd = ft_get_elemi(env, "PWD")) != -1)
		{
			tmp = ft_strjoin("OLD", env[ipwd]);
			new_env = ft_dbarr_edit(env, tmp, iold);
			new_env = ft_dbarr_edit(new_env, tmp_new, ipwd);
			ft_strdel(&tmp);
		}
		else
			new_env = ft_dbarr_add(ft_dbarr_edit(env, "OLDPWD=", iold),
				tmp_new);
	}
	else
		new_env = ft_change_pwd_2(env, tmp_new);
	ft_strdel(&tmp_new);
	return (new_env);
}

char	**ft_change_pwd_2(char **env, char *tmp_new)
{
	char	*tmp;
	char	**new_env;
	int		ipwd;

	if ((ipwd = ft_get_elemi(env, "PWD")) != -1)
	{
		tmp = ft_strjoin("OLD", env[ipwd]);
		new_env = ft_dbarr_add(env, tmp);
		new_env = ft_dbarr_edit(new_env, tmp_new, ipwd);
		ft_strdel(&tmp);
	}
	else
	{
		new_env = ft_dbarr_add(env, "OLDPWD=");
		new_env = ft_dbarr_add(new_env, tmp_new);
	}
	return (new_env);
}

pid_t	ft_pid(pid_t pid, int mode)
{
	static pid_t	save_pid;

	if (mode == 1)
		save_pid = pid;
	return (save_pid);
}
