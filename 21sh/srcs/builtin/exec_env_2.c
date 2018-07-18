/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegros <slegros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:12:25 by slegros           #+#    #+#             */
/*   Updated: 2018/05/12 12:49:46 by slegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				ft_exec_env_args_2(char *tmp_line, char **tmp_env)
{
	char	**save_env;
	int		ret;

	save_env = ft_dbarrdup(ft_env(NULL, 0));
	ft_env(tmp_env, 2);
	ret = ft_check(tmp_line);
	ft_env(save_env, 2);
	save_env = ft_dbarr_free(save_env);
	return (ret);
}

static char		**ft_exec_setenv_add(char **new_env, char *str, int *ret)
{
	char	*name;
	int		i;

	name = ft_strsub(str, 0, ft_strichr(str, '='));
	if (ft_check_name(name) == -1)
	{
		ft_putstr_col_fd("21sh: setenv: Incorrect identifer: ", YEL, 2);
		ft_putendl_col_fd(name, YEL, 2);
		*ret = 1;
	}
	else
	{
		ft_putstr_col_fd("21sh: setenv: Success: ", GRN, 1);
		ft_putendl_col_fd(str, GRN, 1);
		if ((i = ft_get_elemi(new_env, name)) == -1)
			new_env = ft_dbarr_add(new_env, str);
		else
		{
			free(new_env[i]);
			new_env[i] = ft_strdup(str);
		}
	}
	free(name);
	return (new_env);
}

int				ft_exec_setenv(t_cmd cmd, char **env)
{
	int		i;
	int		ret;
	char	**new_env;

	if (cmd.opt != NULL)
		return (ft_env_error(cmd.opt, 3));
	if (cmd.args == NULL)
		return (ft_env_error(NULL, 2));
	new_env = ft_dbarrdup(env);
	ret = 0;
	i = 0;
	while (cmd.args[i] != NULL)
	{
		if (ft_strichr(cmd.args[i], '=') > 0)
			new_env = ft_exec_setenv_add(new_env, cmd.args[i], &ret);
		else
			ret = ft_env_error(cmd.args[i], 6);
		i++;
	}
	ft_env(new_env, 2);
	new_env = ft_dbarr_free(new_env);
	return (ret);
}

static char		**ft_exec_unsetenv_del(char **new_env, char *str, int *ret)
{
	int		i;

	if ((i = ft_get_elemi(new_env, str)) == -1)
	{
		*ret = 1;
		ft_putstr_col_fd("unsetenv: Identifer doesn't exist: ", YEL, 2);
		ft_putendl_col_fd(str, YEL, 2);
	}
	else
	{
		ft_putstr_col_fd("21sh: unsetenv: Success: ", GRN, 1);
		ft_putendl_col_fd(str, GRN, 1);
		new_env = ft_dbarr_del(new_env, i);
	}
	return (new_env);
}

int				ft_exec_unsetenv(t_cmd cmd, char **env)
{
	int		i;
	int		ret;
	char	**new_env;

	if (cmd.opt != NULL)
		return (ft_env_error(cmd.opt, 8));
	if (cmd.args == NULL)
		return (ft_env_error(NULL, 7));
	new_env = ft_dbarrdup(env);
	ret = 0;
	i = 0;
	while (cmd.args[i] != NULL)
	{
		if (ft_check_name(cmd.args[i]) == 1)
			new_env = ft_exec_unsetenv_del(new_env, cmd.args[i], &ret);
		else
			ret = ft_env_error(cmd.args[i], 9);
		i++;
	}
	ft_env(new_env, 2);
	new_env = ft_dbarr_free(new_env);
	return (0);
}
