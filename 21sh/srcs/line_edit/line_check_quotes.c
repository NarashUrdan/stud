/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_check_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegros <slegros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:33:14 by swann             #+#    #+#             */
/*   Updated: 2018/04/20 17:33:42 by slegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_brk	ft_init_brk(void)
{
	t_brk	b;

	b.cursh = 0;
	b.subsh = 0;
	b.quote = 0;
	b.dquote = 0;
	b.bquote = 0;
	return (b);
}

static int		ft_new_prompt(t_brk b)
{
	char	*tmp;

	if (b.cursh > 0 || b.subsh > 0 || b.quote > 0
		|| b.dquote > 0 || b.bquote > 0)
	{
		tmp = ft_strnew(0);
		if (b.cursh > 0)
			tmp = ft_strjoinfree(tmp, "cursh ", 1);
		if (b.subsh > 0)
			tmp = ft_strjoinfree(tmp, "subsh ", 1);
		if (b.quote > 0)
			tmp = ft_strjoinfree(tmp, "quote ", 1);
		if (b.dquote > 0)
			tmp = ft_strjoinfree(tmp, "dquote ", 1);
		if (b.bquote > 0)
			tmp = ft_strjoinfree(tmp, "bquote ", 1);
		tmp = ft_strjoinfree(ft_strsubf(tmp, 0, ft_strlen(tmp) - 1), "> ", 1);
		ft_where(2, NULL);
		ft_where(3, tmp);
		free(tmp);
		return (1);
	}
	ft_where(2, NULL);
	ft_where(1, NULL);
	return (0);
}

int				ft_check_quotes(char *str)
{
	t_brk	b;
	int		i;

	i = -1;
	b = ft_init_brk();
	while (str[++i] != '\0')
	{
		if (str[i] == '(' && b.quote == 0 && b.dquote == 0 && b.bquote == 0)
			b.cursh++;
		if (str[i] == ')' && b.quote == 0 && b.dquote == 0 && b.bquote == 0)
			b.cursh--;
		if (str[i] == '{' && b.quote == 0 && b.dquote == 0 && b.bquote == 0)
			b.subsh++;
		if (str[i] == '}' && b.quote == 0 && b.dquote == 0 && b.bquote == 0)
			b.subsh--;
		if (str[i] == 39 && b.dquote == 0 && b.bquote == 0)
			b.quote = (b.quote == 0) ? 1 : 0;
		if (str[i] == 34 && b.quote == 0 && b.bquote == 0)
			b.dquote = (b.dquote == 0) ? 1 : 0;
		if (str[i] == 96)
			b.bquote = (b.bquote == 0) ? 1 : 0;
		if (str[i] == 92)
			i++;
	}
	return (ft_new_prompt(b));
}
