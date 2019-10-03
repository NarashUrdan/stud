/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 14:49:05 by jukuntzm          #+#    #+#             */
/*   Updated: 2019/10/03 15:25:08 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

void    show_alloc_mem()
{
    t_page *Tiny;
    t_page *Small;
    t_page *Large;

    save_struct(Tiny, Small, Large, 1);
    ft_putstr("TINY : ");
    while(Tiny->next != NULL){
        ft_putendl();
    }
    ft_putstr("SMALL : ");
    ft_putstr("LARGE : ");
    
}
