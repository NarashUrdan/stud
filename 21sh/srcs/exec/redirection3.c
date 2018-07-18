/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <jukuntzm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:11:52 by slegros           #+#    #+#             */
/*   Updated: 2018/05/15 15:57:26 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				ft_error_fd(char *files)
{
	ft_putstr_col_fd("21sh: Bad file descriptor: ", YEL, 2);
	ft_putendl_col_fd(files + 1, YEL, 2);
	return (-2);
}

static int		*ft_fdnew(void)
{
	int		*fd;

	if (!(fd = (int *)malloc(sizeof(int) * 2)))
		return (fd);
	return (fd);
}

static void		ft_redirection2_free(t_tree *tree, char **tmp, char **str)
{
	free(tree->op);
	free(tree);
	free(*tmp);
	free(*str);
}

int				*ft_redirection2(char *str)
{
	int		*fd;
	t_tree	*tree;
	char	*tmp;

	fd = ft_fdnew();
	fd[0] = -1;
	if (!(tree = (t_tree *)malloc(sizeof(t_tree))))
		return (fd);
	tmp = ft_strdup(str);
	tree->op = ft_strnew(0);
	if (!ft_strncmp(str, "&>", 2))
	{
		tmp[0] = '1';
		tree->op = ft_strjoinfree(tree->op, tmp, 1);
		tmp[0] = '2';
		tmp = ft_strinsert(tmp, 62, ft_strichr(tmp, 62));
		tree->op = ft_strjoinfree(tree->op, ";", 1);
		tree->op = ft_strjoinfree(tree->op, tmp, 1);
		free(fd);
		fd = ft_redirection(tree);
	}
	else
		fd = ft_redirection3(tmp, tree, fd);
	ft_redirection2_free(tree, &tmp, &str);
	return (fd);
}

int				ft_check_redtmp(t_lex *tmp)
{
	int		i;
	int		l;
	char	c;

	if (!ft_strcmp(tmp->type, "red"))
	{
		c = (ft_strchr(tmp->data, 60) != NULL) ? 60 : 62;
		i = ft_strnbstr(tmp->data, 60);
		l = ft_strnbstr(tmp->data, 62);
		if (ft_strlen(tmp->data) == 2 && !ft_isdigit(tmp->data[0]) &&
			!ft_isdigit(tmp->data[1]))
			return (c);
		if (((c == 60 && i <= 2 && l == 0) || (c == 62 && l <= 2 && i == 0)) &&
		((int)ft_strlen(tmp->data) != (i + l)))
			return (0);
		return (c);
	}
	if (!ft_strcmp(tmp->type, "sep"))
		return (ft_check_sep(tmp));
	return (0);
}
