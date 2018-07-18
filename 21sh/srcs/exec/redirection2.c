/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <jukuntzm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 13:50:35 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/05/10 18:08:15 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int		ft_red_agg2(char *files, char *str)
{
	int		fd;

	fd = ft_strlen(files);
	if (!ft_isdigit(files[fd - 1]) && files[0] != '&')
	{
		if (str[0] != ' ' && str[0] != '1')
		{
			ft_putstr_col_fd("21sh: ambiguous redirect: ", YEL, 2);
			ft_putendl_col_fd(files + 2, YEL, 2);
			return (-2);
		}
	}
	if (ft_isdigit(files[fd - 1]) && ft_atoi(&files[fd - 1]) > 2
		&& !ft_strstr(str, "<"))
		return (ft_error_fd(files));
	files = ft_strdup(str);
	files = ft_strrem(files, ft_strichr(files, 38));
	fd = (ft_strchr(files, 62) != NULL) ?
	ft_red_right(files) : ft_red_left(files, -1);
	free(files);
	return (fd);
}

int				ft_red_agg(char *str)
{
	char	*files;
	int		fd;

	fd = 0;
	files = ft_strrchr(str, str[1]);
	if (ft_strchr(files, 38) && ft_strichr(files, 45) == -1)
		fd = ft_red_agg2(files, str);
	else if (str[ft_strlen(str) - 1] == '-')
	{
		fd = open("/dev/null", O_CREAT | O_WRONLY);
		if (ft_isdigit(str[0]))
			dup2(fd, ft_atoi(&str[0]));
		else
			dup2(fd, 1);
	}
	else if (ft_isdigit(str[0]))
		dup2(ft_atoi(&files[1]), ft_atoi(&str[0]));
	else
		dup2(ft_atoi(&files[1]), 1);
	if (fd == -1)
	{
		fd = ft_error_fd(files);
		fd = -2;
	}
	return (fd);
}

void			restore_fds(void)
{
	t_fds		*fds;

	fds = get_terminal();
	if (fds->fd_stdin != -1)
		dup2(fds->fd_stdin, STDIN_FILENO);
	else
		close(STDIN_FILENO);
	if (fds->fd_stderr != -1)
		dup2(fds->fd_stderr, STDERR_FILENO);
	else
		close(STDERR_FILENO);
	if (fds->fd_stdout != -1)
		dup2(fds->fd_stdout, STDOUT_FILENO);
	else
		close(STDOUT_FILENO);
}

static t_fds	*init_fds(void)
{
	t_fds		*fds;

	if (!(fds = malloc(sizeof(t_fds))))
		return (NULL);
	fds->fd_stdin = 100;
	fds->fd_stdout = 101;
	fds->fd_stderr = 102;
	if (dup2(0, fds->fd_stdin) == -1)
	{
		close(fds->fd_stdin);
		fds->fd_stdin = -1;
	}
	if (dup2(STDERR_FILENO, fds->fd_stderr) == -1)
	{
		close(fds->fd_stderr);
		fds->fd_stderr = -1;
	}
	if (dup2(STDOUT_FILENO, fds->fd_stdout) == -1)
	{
		close(fds->fd_stdout);
		fds->fd_stdout = -1;
	}
	return (fds);
}

t_fds			*get_terminal(void)
{
	static t_fds	*fds = NULL;

	if (fds == NULL)
		fds = init_fds();
	return (fds);
}
