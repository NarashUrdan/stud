/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegros <slegros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 09:55:59 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/05/14 14:25:03 by slegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char		*ft_getpath_error(int i, char *cmd)
{
	if (i == -2)
	{
		ft_putstr_col_fd("21sh: Permission denied: ", YEL, 2);
		ft_putendl_col_fd(cmd, YEL, 2);
		ft_exit_value(1, 126);
	}
	else
	{
		ft_putstr_col_fd("21sh: Command not found: ", YEL, 2);
		ft_putendl_col_fd(cmd, YEL, 2);
		ft_exit_value(1, 127);
	}
	return (NULL);
}

static char		*ft_getpath(char *cmd, char **env)
{
	char	*path;
	char	**multipath;
	int		i;

	multipath = NULL;
	if ((path = ft_get_elem(env, "PATH")) != NULL)
		multipath = ft_strsplit(path, ':');
	i = ft_get_iaccess(multipath, cmd);
	free(path);
	if (i >= 0)
	{
		path = ft_strjoin(multipath[i], "/");
		path = ft_strjoinfree(path, cmd, 1);
	}
	else if (i == -1)
		path = ft_strdup(cmd);
	else
		path = ft_getpath_error(i, cmd);
	if (multipath != NULL)
		multipath = ft_dbarr_free(multipath);
	return (path);
}

static int		ft_exec_norme(int i)
{
	int		ret;

	if (WIFSIGNALED(i))
		ret = WTERMSIG(i) + 128;
	else
		ret = WEXITSTATUS(i);
	ft_term(1);
	ft_pid(-1, 1);
	restore_fds();
	return (ret);
}

int				ft_exec(t_tree *tree, char **env)
{
	char		*path;
	int			i;
	pid_t		pid;

	i = 0;
	if (!tree)
		return (2);
	if ((path = ft_getpath(tree->cmd, env)) == NULL)
		return (ft_exit_value(0, 0));
	pid = fork();
	if (pid == 0 && i != -1)
		i = execve(path, tree->args, env);
	if (path != NULL)
		free(path);
	ft_pid(pid, 1);
	waitpid(-1, &i, WUNTRACED | WCONTINUED);
	if (!(WIFEXITED(i)))
		return (ft_exec_norme(i));
	ft_pid(-1, 1);
	restore_fds();
	return (WEXITSTATUS(i));
}
