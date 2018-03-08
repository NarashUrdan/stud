/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 01:58:56 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/03/08 05:37:19 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

t_lex	**ft_rectree(t_lex **tree, t_lex **cmd, int nb, int s1)
{
	t_lex	*p1;
	t_lex	*p2;

	if (s1 == 1)
		return (cmd);
	p1 

}

int 	parser(t_lex **cmd)
{
	t_lex *tmp;
	t_lex *tree;
	t_lex *sep;

	tree = malloc(sizeof(t_lex));
	tmp = *cmd;
	while (cmd->next)
		cmd = cmd->next;
	sep = tmp;
	while (sep->prev && ft_strcmp(sep->type, "sep"))
		sep = sep->prev;
	tree = ft_rectree(tree, tmp, tmp ->value, sep->value);
	return (0);
}
