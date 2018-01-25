/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 04:39:12 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/01/25 03:56:48 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_isarg(char arg, t_ar *ar)
{
	ar->a = (ar->a == 1 || arg == 'a') ? 1 : 0;
	ar->r = (ar->r == 1 || arg == 'r') ? 1 : 0;
	ar->re = (ar->re == 1 || arg == 'R') ? 1 : 0;
	ar->l = (ar->l == 1 || arg == 'l') ? 1 : 0;
	ar->t = (ar->t == 1 || arg == 't') ? 1 : 0;
	if (arg != 'a' && arg != 'l' && arg != 'r' && arg != 'R' && arg != 't')
		return (1);
	return (0);
}

int		ft_ar(char **argv, t_ar *ar, char **multipath)
{
	int i;
	int	j;

	i = 1;
	while (argv[i] && argv[i][0] == '-')
	{
		j = 1;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || ft_isarg(argv[i][j], ar))
			{
				ft_error("ft_ls: illegal option -- ", argv[i][j]);
				return (1);
			}
			j++;
		}
		i++;
	}
	if (ft_path(argv, multipath, i, ar))
		return (1);
	return (0);
}

t_ar	ft_init(void)
{
	t_ar ar;

	ar.r = 0;
	ar.l = 0;
	ar.re = 0;
	ar.a = 0;
	ar.t = 0;
	return (ar);
}

int		main(int argc, char **argv)
{
	t_ar	ar;
	char	**multipath;

	multipath = NULL;
	ar = ft_init();
	if (argc > 1)
	{
		if (ft_ar(argv, &ar, multipath))
			return (0);
	}
	else
		ft_path(argv, multipath, 1, &ar);
	return (0);
}
