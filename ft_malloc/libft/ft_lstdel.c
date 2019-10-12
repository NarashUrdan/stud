/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 00:35:38 by jukuntzm          #+#    #+#             */
/*   Updated: 2017/11/14 00:52:19 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*elem;
	t_list	*next;

	elem = *alst;
	while (elem != NULL)
	{
		next = elem->next;
		del(elem->content, elem->content_size);
		free(elem);
		elem = next;
	}
	*alst = NULL;
}
