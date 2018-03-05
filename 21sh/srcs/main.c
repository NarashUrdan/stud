/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 10:38:25 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/03/05 00:18:41 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

int	main(int argc, char **argv)
{
	int	i;
	int	l;
	char	*str;

	i = 1;
	while (i < argc)
	{
		l = ft_strlen(argv[i]);
		str = (char *)malloc(sizeof(char) * l + 2);
		str = ft_strcpy(str, argv[i]);
		str[l] = '\n';
		str[l + 1] = '\0';
		ft_putstr_fd(str, 2);
		ft_check(str);
		i++;
	}
	return (0);
}
