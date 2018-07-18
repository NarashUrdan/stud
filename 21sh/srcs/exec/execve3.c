/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegros <slegros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:26:38 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/05/01 16:42:21 by slegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int		ft_launch_builtin(t_tree *tree, int i, t_cmd cmd, char **env)
{
	if (ft_strcmp(tree->cmd, "exit") == 0)
		i = ft_exec_exit(cmd);
	else if (ft_strcmp(tree->cmd, "history") == 0)
		i = ft_exec_history(cmd);
	else if (ft_strcmp(tree->cmd, "cd") == 0)
		i = ft_exec_cd(cmd);
	else
		i = ft_prexec_env(cmd, env);
	return (i);
}

int				ft_check_builtin(t_tree *tree, int i, char **env)
{
	t_cmd	cmd;

	if (ft_strcmp(tree->cmd, "echo") == 0)
		i = ft_exec_echo(tree->args);
	else if (ft_strcmp(tree->cmd, "exit") == 0
		|| ft_strcmp(tree->cmd, "history") == 0
		|| ft_strcmp(tree->cmd, "setenv") == 0
		|| ft_strcmp(tree->cmd, "unsetenv") == 0
		|| ft_strcmp(tree->cmd, "env") == 0
		|| ft_strcmp(tree->cmd, "cd") == 0)
	{
		if (ft_strcmp(tree->cmd, "cd") == 0)
			cmd = ft_conversion_cd(tree->args);
		else
			cmd = ft_conversion(tree->args);
		i = ft_launch_builtin(tree, i, cmd, env);
		ft_clean_cmd(cmd);
	}
	else
		i = ft_exec(tree, env);
	restore_fds();
	return (i);
}

int				ft_exec_left_bq(t_tree *tree, int i, int pfd[])
{
	close(pfd[0]);
	dup2(pfd[1], 1);
	i = ft_sep(tree->left, i);
	write(1, "\n", 1);
	close(pfd[1]);
	restore_fds();
	return (i);
}

int				ft_exec_bq(t_tree *tree, int i, char **env)
{
	int		pfd[2];

	if ((pipe(pfd) == -1))
		return (1);
	if (fork() == 0)
	{
		i = ft_exec_left_bq(tree, i, pfd);
		exit(i);
	}
	if (fork() == 0)
	{
		close(pfd[1]);
		dup2(pfd[0], 0);
		tree->args = ft_new_args(tree, pfd);
		i = ft_exec(tree, env);
		restore_fds();
		exit(i);
	}
	wait(NULL);
	wait(NULL);
	return (i);
}
