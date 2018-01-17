/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 00:54:12 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/01/17 05:26:23 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*ft_att(char **argv, char *ar)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 1;
	str = NULL;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-')
		{
			while (argv[i][j++]) 
			{
				if (argv[i][j] == '-')
					return (NULL);
				ar[k++] = argv[i][j];
			}
			k = 0;
		}
		else
		{
			if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(argv[i]) + 1))))
				return (NULL);
			while (argv[i][j] != '\0')
				str[k++] = argv[i][j++];
		}
		i++;
	}
	if (str == NULL)
	{	
		str = ft_strnew(0);
		str = (char *)ft_memset((void *)str, 46, 1);
	}	
	return (str);
}

int	check_error(char *ar)
{
	int i;

	i = 0;
	while (ar[i])
	{
		if (ar[i] != 't' && ar[i] !='l' && ar[i] != 'a' && ar[i] != 'r' && ar[i] !='t')
			return (1);
		i++;
	}
	return (0);
}

t_ar	ft_ar(char *str)
{
	t_ar	ar;

	ar.a = ((strrchr(str, 97)) == NULL) ? 0 : 1;
	ar.r = ((strrchr(str, 114)) == NULL) ? 0 : 1;
	ar.re = ((strrchr(str, 82)) == NULL) ? 0 : 1;
	ar.l = ((strrchr(str, 108)) == NULL) ? 0 : 1;
	ar.t = ((strrchr(str, 116)) == NULL) ? 0 : 1;
	return (ar);
}

int main(int argc, char **argv)
{
	char	ar[6];
	int	i;
	char *path;
	(void)argc;

	i = 0;
	if ((path = ft_att(argv, ar)) == NULL)
	{
		ft_putendl("error");
		return (0);
	}
	if (check_error(ar) == 1)
	{
		ft_putendl("error");
		return (0);
	}
	if (ft_open(path, ft_ar(ar)) == 1)
	{
		ft_putendl("error");
		return (0);
	}
	return (0);
}
