/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_edit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegros <slegros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 19:12:11 by slegros           #+#    #+#             */
/*   Updated: 2018/05/08 16:21:01 by slegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		ft_line_2(char *buf)
{
	if ((buf[0] == 21 || buf[0] == 16 || buf[0] == 11) && buf[1] == '\0')
		ft_history(15, NULL, buf[0]);
	else if (buf[0] == 4 && buf[1] == '\0')
		ft_history(17, NULL, ft_button_line(0, 0));
	else if (buf[0] == 9 && buf[1] == '\0')
		ft_history(18, NULL, 0);
}

static void		ft_line(char *buf)
{
	if (((buf[0] >= 32 && buf[0] <= 126) || buf[0] == 10) && buf[1] == '\0')
		ft_history(3, buf, 0);
	else if (buf[0] == 27 && buf[1] == 91 && (buf[2] == 65 || buf[2] == 66)
		&& buf[3] == '\0')
		ft_history(4, NULL, (buf[2] * 2) - 131);
	else if (buf[0] == 27 && buf[1] == 91 && (buf[2] == 67 || buf[2] == 68)
		&& buf[3] == '\0')
		ft_history(7, NULL, (buf[2] * 2) - 135);
	else if (buf[0] == 127 && buf[1] == '\0')
		ft_history(8, buf, 0);
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 51 && buf[3] == 126
		&& buf[4] == '\0')
		ft_history(9, buf, 0);
	else if (buf[0] == 27 && buf[1] == 91 && buf[3] == '\0'
		&& (buf[2] == 70 || buf[2] == 72))
		ft_history(11, NULL, buf[2] - 71);
	else if (buf[0] == 50 && buf[2] == '\0' && (buf[1] == 67 || buf[1] == 68))
		ft_history(12, NULL, (buf[1] * 2) - 135);
	else if (buf[0] == 50 && buf[2] == '\0' && (buf[1] == 65 || buf[1] == 66))
		ft_history(16, NULL, (buf[1] * 2) - 131);
	else if (buf[0] == 12 && buf[1] == '\0')
		ft_history(14, NULL, 0);
	else
		ft_line_2(buf);
}

static void		ft_set_line(char **line)
{
	t_h		tmp;

	ft_history(5, NULL, 0);
	tmp = ft_history(0, NULL, 0);
	ft_hist_return(tmp, 1);
	if (ft_button_line(0, 0) == 1 || ft_button_line(0, 0) == 3)
	{
		ft_button_line(0, 0) == 3 ? free(*line) : 0;
		*line = ft_strdup(tmp.hist[ft_dbarrlen(tmp.hist) - 1]);
		ft_button_line(1, 1);
		ft_heredoc(*line, 0, 1);
	}
	else if (ft_button_line(0, 0) == 4)
	{
		if (ft_strlen(tmp.hist[ft_dbarrlen(tmp.hist) - 1]) != 0)
			ft_heredoc(tmp.hist[ft_dbarrlen(tmp.hist) - 1], 0, 5);
	}
	else
	{
		*line = ft_strjoinfree(*line, "\n", 1);
		*line = ft_strjoinfree(*line, tmp.hist[ft_dbarrlen(tmp.hist) - 1], 1);
		ft_history(23, NULL, 0);
		ft_heredoc(NULL, 0, 4);
		ft_heredoc(*line, 0, 1);
	}
}

static void		ft_read_check_line(char **line)
{
	if (ft_button_line(0, 0) != 4)
	{
		if (ft_inread_parsing(*line) != 1)
		{
			if (ft_check_quotes(*line) != 0)
				ft_read_line(line, ft_button_line(1, 2));
			if (ft_check_op(*line) != 0)
			{
				if (ft_strlen(ft_where(0, NULL)) >= 14
					|| ft_strncmp("heredoc", ft_where(0, NULL), 7) == 0)
					ft_read_line(line, ft_button_line(1, 4));
				else
					ft_read_line(line, ft_button_line(1, 2));
			}
		}
		else
			*line[0] = '\0';
	}
}

void			ft_read_line(char **line, int mode)
{
	char	buf[5];

	if (mode == 2 || mode == 4)
		ft_putstr_col_fd(ft_where(0, NULL), BOLD, 0);
	ft_bzero(buf, 5);
	ft_history(2, NULL, 0);
	while (read(0, buf, 4))
	{
		if (ft_strichr(buf, '\n') != -1)
			break ;
		if (buf[0] == 4 && buf[1] == '\0' && ft_button_line(0, 0) == 4 && nbl())
		{
			ft_history(25, NULL, 0);
			break ;
		}
		ft_line(buf);
		ft_bzero(buf, 5);
	}
	ft_set_line(line);
	if (ft_button_line(0, 0) == 4)
	{
		if (ft_heredover() == 1)
			ft_read_line(line, ft_button_line(1, 4));
	}
	ft_read_check_line(line);
}
