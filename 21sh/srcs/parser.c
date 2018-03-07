/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 01:58:56 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/03/07 07:01:21 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

int parser(t_lex **cmd)
{
	t_lex *tmp;
	t_lex *tree;

	tree = malloc(sizeof(t_lex));
	tmp = *cmd;
	while (tmp)
		tmp->next;
	while (tmp->prev && ft_strcmp(tmp->data, ";"))

		
	return (0);
}
