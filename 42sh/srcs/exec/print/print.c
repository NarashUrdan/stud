/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegros <slegros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 14:14:10 by amottier          #+#    #+#             */
/*   Updated: 2018/05/10 14:05:15 by slegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		print_prompt(int i)
{
	ft_putstr_fd("\033[31m", 0);
	if (i == 1)
		ft_putchar('\n');
	ft_putstr_fd("➜  ", 0);
	ft_putstr_fd("\033[0m", 0);
}