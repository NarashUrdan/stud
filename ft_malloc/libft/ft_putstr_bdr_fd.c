/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bdr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 01:42:03 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/12 01:42:04 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_bdr_fd(char const *s, char bdr, int fd)
{
	ft_putchar_fd(bdr, fd);
	ft_putstr_fd(s, fd);
	ft_putchar_fd(bdr, fd);
}
