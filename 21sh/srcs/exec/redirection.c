/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <jukuntzm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:46:47 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/05/10 19:20:53 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				ft_red_right(char *str)
{
	char	*files;
	int		fd;
	char	c;

	c = str[0];
	fd = -1;
	files = ft_strrchr(str, 62) + 1;
	while (files[0] == ' ')
		files = files + 1;
	fd = -1;
	if (access(files, W_OK) == -1 && access(files, F_OK) == 0)
	{
		ft_putendl_col_fd("21sh: Permission denied", YEL, 2);
		return (0);
	}
	if (ft_isdigit(files[0]))
		fd = ft_atoi(&files[0]);
	else if (ft_strstr(str, ">>") == NULL || access(files, F_OK) == -1)
		fd = open(files, O_CREAT | O_TRUNC | O_RDWR, S_IRWXU
			| S_IRWXG | S_IRWXO);
	else
		fd = open(files, O_APPEND | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);
	fd = (c == 62 || c == '1') ? dup2(fd, 1) : dup2(fd, ft_atoi(&c));
	return (fd);
}

static int		ft_red_left2(int j, int l, int fd)
{
	t_her	esie;

	esie = ft_heredoc(NULL, 0, 0);
	fd = open("/private/tmp/.her", O_CREAT | O_TRUNC | O_WRONLY,
	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (esie.i != 0)
	{
		while (l < esie.i)
		{
			while (ft_strcmp(esie.stock[j], esie.stop[l]))
				j++;
			l++;
		}
	}
	j = (j == 0) ? -1 : j;
	while (esie.stock[++j] != NULL &&
		ft_strcmp(esie.stock[j], esie.stop[esie.i]))
		ft_putendl_fd(esie.stock[j], fd);
	ft_heredoc(NULL, 0, 7);
	close(fd);
	fd = open("/private/tmp/.her", O_APPEND | O_RDONLY,
	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	dup2(fd, 0);
	return (fd);
}

int				ft_red_left(char *str, int fd)
{
	char	*files;
	int		j;
	int		l;

	l = 0;
	j = 0;
	files = ft_strrchr(str, 60) + 1;
	while (files[0] == ' ')
		files = files + 1;
	if (!ft_strstr(str, "<<") && ft_check_file(files) == -2)
		return (-2);
	if (ft_strstr(str, "<<") == NULL)
	{
		if (ft_isdigit(files[0]))
			fd = dup2(0, ft_atoi(&files[0]));
		else
		{
			fd = open(files, O_RDONLY, S_IRWXU | S_IRWXG | S_IRWXO);
			dup2(fd, 0);
		}
	}
	else
		fd = ft_red_left2(j, l, -1);
	return (fd);
}

static int		*ft_chooseyourred(char **red, int i, int *fd)
{
	int	l;

	l = 0;
	while (red[i] != NULL)
	{
		while ((l = ft_strichr(red[i], 32)) != -1)
			red[i] = ft_strrem(red[i], l);
		red[i] = ft_redquote(&red[i]);
		if (red[i][0] != '&' && red[i][0] != 60 && red[i][0] != 62
			&& !ft_isdigit(red[i][0]))
			dup2(3, 1);
		else if ((red[i][0] == '&' || red[i][1] == '&')
			&& !ft_strstr(red[i], ">&") && !ft_strstr(red[i], "<&"))
			fd = ft_strjoindint(ft_redirection2(ft_strdup(red[i])), fd);
		else if (ft_strchr(red[i], 38) != NULL)
			fd[i] = ft_red_agg(red[i]);
		else if (ft_strchr(red[i], 62) != NULL)
			fd[i] = ft_red_right(red[i]);
		else
			fd[i] = ft_red_left(red[i], -1);
		i++;
	}
	fd = ft_checkfd(fd);
	return (fd);
}

int				*ft_redirection(t_tree *tree)
{
	char	**red;
	int		*fd;
	char	*tmp;

	if (!(fd = (int *)malloc(sizeof(int) * (1))))
		return (NULL);
	fd[0] = -1;
	if (tree->op[0] == '\0')
		return (fd);
	tmp = ft_strdup(tree->op);
	red = ft_strsplit(tmp, ';');
	free(fd);
	fd = init_fd(red);
	if (red[0] == '\0')
	{
		red = ft_dbarr_free(red);
		return (fd);
	}
	fd = ft_chooseyourred(red, 0, fd);
	free(tmp);
	red = ft_dbarr_free(red);
	return (fd);
}
