/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bdr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 01:41:39 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/12 01:41:42 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_bdr(char const *s, char bdr)
{
	ft_putchar(bdr);
	ft_putstr(s);
	ft_putchar(bdr);
}
