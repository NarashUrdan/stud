/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 05:47:07 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/19 01:52:01 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*lst2;

	lst = *alst;
	while (lst)
	{
		lst2 = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = lst2;
	}
	*alst = NULL;
}
