/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 09:30:34 by jukuntzm          #+#    #+#             */
/*   Updated: 2019/09/19 10:29:02 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/mman.h>
#include "../libft/libft.h"

void	free(void *ptr);
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);
