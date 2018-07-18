/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 06:09:33 by jukuntzm          #+#    #+#             */
/*   Updated: 2017/11/21 04:42:53 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*lst2;
	t_list	*lst3;

	lst3 = f(lst);
	if (!(new = ft_lstnew(lst3->content, lst3->content_size)))
		return (NULL);
	lst2 = new;
	lst = lst->next;
	while (lst)
	{
		lst3 = f(lst);
		if (!(new->next = ft_lstnew(lst3->content, lst3->content_size)))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (lst2);
}
