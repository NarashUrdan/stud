/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 14:49:05 by jukuntzm          #+#    #+#             */
/*   Updated: 2019/10/12 15:52:02 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

void    print_hex(unsigned char value, int index)
{
    if (index < 2)
    {
        print_hex(value / 16, index + 1);
        if (value % 16 >= 10) {
            ft_putchar('a' + value % 16 % 10);
        }
        else if (value % 16 >= 0){
            ft_putchar('0' + value % 16);
        }
    }
}

int    print_memory(const void *addr, size_t size)
{
    char    *ptr;
    size_t  i;

    if (addr && size > 0)
    {
      ptr = (char *)addr;
        i = size;
        write(1,"0x", 2);
        while (i > 0)
        {
            print_hex(ptr[i], 0);
            i--;
        }
        print_hex(ptr[0], 0);
    }
    return 0;
}

void    print(t_page *mem){
        print_memory(Tiny->str[0], 1);
        ft_putstr(" - ");
        print_memory(Tiny->str[Tiny->len], 1);
        ft_putstr(" : ");
        ft_putnbr(Tiny->len);
        ft_putendl(" octets");
}

void    show_alloc_mem()
{
    t_page *Tiny;
    t_page *Small;
    t_page *Large;

    save_struct(Tiny, Small, Large, 1);
    ft_putstr("TINY : ");

    while(Tiny->next != NULL){
        print(Tiny);
        Tiny = Tiny->next;
    }
    print(Tiny);
    ft_putstr("SMALL : ");
    while(Small->next != NULL){
        print(Small);
        Small = Small->next;
    }
    print(Small);
    ft_putstr("LARGE : ");
    while(Large->next != NULL){
        print(Large);
        Large = Large->next;
    }
    print(Large);
    
}
