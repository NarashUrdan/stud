/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegros <slegros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 21:38:26 by swann             #+#    #+#             */
/*   Updated: 2018/05/03 14:03:57 by slegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char			*ft_heredoc_save(char *str, int mode)
{
	static char		*save;

	if (mode == 1)
		save = ft_strdup(str);
	if (mode == 2)
		free(save);
	return (save);
}

int				ft_heredover(void)
{
	t_h		the;
	int		res;

	the = ft_history(0, NULL, 0);
	if (ft_strcmp(the.hist[the.i], ft_heredoc_save(NULL, 0)) == 0)
	{
		ft_heredoc(NULL, 0, 3);
		res = 0;
		ft_button_line(1, 1);
		ft_heredoc_save(NULL, 2);
	}
	else
		res = 1;
	ft_history(22, NULL, ft_dbarrlen(the.hist) - 1);
	return (res);
}

static void		ft_heredoc_2(char *str, t_her *save, int mode)
{
	int		i;

	if (mode == 3)
	{
		i = 0;
		while (save->val[i] != 1)
			i++;
		save->val[i] = 2;
		save->val[i + 1] = 2;
	}
	if (mode == 4)
	{
		save->stop = ft_dbarr_free(save->stop);
		save->stock = ft_dbarr_free(save->stock);
		free(save->val);
		save->i = 0;
	}
	if (mode == 5)
		save->stock = ft_dbarr_add(save->stock, str);
	if (mode == 6)
		save->stop = ft_dbarr_add(save->stop, str);
	if (mode == 7)
		save->i += 1;
}

t_her			ft_heredoc(char *str, int index, int mode)
{
	static t_her	save;
	int				i;

	if (mode == 1)
	{
		save.i = 0;
		save.stock = ft_dbarrnew(0);
		save.stop = ft_dbarrnew(0);
		if (!(save.val = (int *)malloc(sizeof(int) * ft_strlen(str))))
			return (save);
		i = -1;
		while (++i < (int)ft_strlen(str))
			save.val[i] = 0;
	}
	if (mode == 2)
	{
		save.val[index] = 1;
		save.val[index + 1] = 1;
	}
	if (mode == 3 || mode == 4 || mode == 5 || mode == 6 || mode == 7)
		ft_heredoc_2(str, &save, mode);
	return (save);
}
