/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 04:39:12 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/01/19 05:25:38 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_isarg(char arg, t_ar ar)
{
	ar.a = (arg == 97) ? 1 : 0;
	ar.r = (arg == 114) ? 1 : 0;
	ar.re = (arg == 82) ? 1 : 0;
	ar.l = (arg == 108) ? 1 : 0;
	ar.t = (arg == 116) ? 1 : 0;
	if (!(ar.a && ar.r && ar.re && ar.l && ar.t))
		ft_error("ft_ls: illegal option --", arg);
}

int	ft_ar(char **argv, t_ar ar)
{
	int i;
	int	j;

	i = 0;
	while(argv[i] && argv[i][0] == '-')
	{
		j = 1;
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
				ft_error("ft_ls: illegal option --", argv[i][j]);
			ft_isarg(argv[i][j], ar);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
//	t_lst	files;
	t_ar	ar;

	ar = ft_memalloc(sizeof(ar));
	if (argc > 1)
		ft_ar(argv, ar);
		ft_putnbr(ar.a);
	return (0);
}
