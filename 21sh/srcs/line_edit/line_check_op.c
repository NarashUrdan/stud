/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_check_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <jukuntzm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:28:30 by slegros           #+#    #+#             */
/*   Updated: 2018/05/12 13:19:33 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char		*ft_hend(char *str, int index)
{
	int		i;
	int		j;
	char	*res;
	int		but;

	i = index;
	res = NULL;
	but = 0;
	while (str[i] != '\0' && ft_isspace(str[i]) == 1)
		i++;
	j = i;
	while (str[j] != '\0' && !ft_issep(str[j]) &&
		(ft_isspace(str[j]) == 0 || but != 0))
	{
		if ((str[j] == 34 || str[j] == 39 || str[j] == 96) && but == 0)
			but = str[j];
		else if (but == str[j])
			but = 0;
		j++;
	}
	if (j > i)
		res = ft_strsub(str, i, j - i);
	return (res);
}

static void		ft_check_heredoc_2(char *tmp2, int i, char **prompt)
{
	ft_heredoc_save(tmp2, 1);
	ft_heredoc(tmp2, 0, 6);
	ft_heredoc(NULL, i, 2);
	if (*prompt == NULL)
		*prompt = ft_strdup("heredoc");
	else
		*prompt = ft_strjoinfree(*prompt, " heredoc", 1);
}

static char		*ft_check_heredoc(char *prompt, char *line)
{
	int		i;
	char	tmp1[2];
	char	*tmp2;
	t_her	get;

	i = 0;
	get = ft_heredoc(NULL, 0, 0);
	while (line[i + 1] != '\0')
	{
		tmp1[0] = line[i];
		tmp1[1] = line[i + 1];
		tmp2 = ft_hend(line, i + 2);
		if (ft_strncmp(tmp1, "<<", 2) == 0 && ft_inbrk(line, i) == 0
			&& ft_inbrk(line, i + 1) == 0 && get.val[i] != 2 && tmp2 != NULL)
		{
			ft_check_heredoc_2(tmp2, i, &prompt);
			free(tmp2);
			return (prompt);
		}
		if (tmp2 != NULL)
			free(tmp2);
		i++;
	}
	return (prompt);
}

static int		ft_check_op_2(char **prompt)
{
	if (*prompt != NULL)
	{
		*prompt = ft_strjoinfree(*prompt, "> ", 1);
		ft_where(2, NULL);
		ft_where(3, *prompt);
		free(*prompt);
		return (1);
	}
	ft_where(2, NULL);
	ft_where(1, NULL);
	return (0);
}

int				ft_check_op(char *str)
{
	int		i;
	char	*prompt;

	prompt = NULL;
	i = ft_strlen(str) - 1;
	while (i >= 0 && ft_isspace(str[i]) == 1)
		i--;
	if (i != -1 && (str[i] == '|' || str[i] == '&'))
	{
		if (str[i] == '&' && i > 0 && str[i - 1] == '&' && str[i - 2] != '\\')
			prompt = ft_strdup("cmdand");
		else if (str[i] == '|')
		{
			if (i > 0 && str[i - 1] == '|' && str[i - 2] != '\\')
				prompt = ft_strdup("cmdor");
			else if (str[i - 1] != '\\')
				prompt = ft_strdup("pipe");
		}
	}
	prompt = (ft_strlen(str) > 0) ? ft_check_heredoc(prompt, str) : prompt;
	return (ft_check_op_2(&prompt));
}
