/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 05:04:49 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/01/19 05:20:19 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_error(char *str, char arg)
{
	ft_putstr(str);
	write(1, &arg, 1);
	ft_putendl("\nusage: ft_ls [-Ralrt] [file ...]");
	break ;
}
