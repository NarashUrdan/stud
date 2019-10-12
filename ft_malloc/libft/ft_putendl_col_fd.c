/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_col_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:07:54 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/15 12:07:55 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_col_fd(char *str, char *col, int fd)
{
	ft_putstr_fd(col, fd);
	ft_putstr_fd(str, fd);
	ft_putendl_fd(RESET, fd);
}
