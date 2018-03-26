/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 10:38:25 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/03/23 14:27:58 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

void	ft_printtree(t_tree *tree)
{
	if (tree == NULL)
	{
		ft_putendl("--end leaf--");
		return ;
	}
	ft_putendl("cmd : ");
	ft_putendl(tree->cmd);
	ft_putendl("op : ");
	ft_putendl(tree->op);
	ft_putendl("args : ");
	ft_putendl(tree->args);
	ft_putendl("--leaf right--");
	ft_printtree(tree->right);
	ft_putendl("--leaf left--");
	ft_printtree(tree->left);
	ft_putendl("--end tree--");
	free(tree->cmd);
	free(tree->op);
	free(tree->args);
	free(tree);
}

int	main(int argc, char **argv)
{
	int	i;
	int	l;
	char	*str;
		(void)argc;
	i = 1;
		l = ft_strlen(argv[i]);
		str = (char *)malloc(sizeof(char) * l + 2);
		str = ft_strcpy(str, argv[i]);
		str[l] = '\n';
		str[l + 1] = '\0';
		ft_putstr_fd(str, 2);
		ft_check(str);
		free(str);
	return (0);
}
