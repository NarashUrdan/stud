/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bdr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 01:40:34 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/12 01:40:34 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_bdr_fd(int n, char bdr, int fd)
{
	ft_putchar_fd(bdr, fd);
	ft_putnbr_fd(n, fd);
	ft_putchar_fd(bdr, fd);
}
