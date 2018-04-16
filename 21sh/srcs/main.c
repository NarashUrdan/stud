/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 10:38:25 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/04/16 17:10:03 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

void	ft_printtree(t_tree *tree)
{
	if (tree == NULL)
	{
//		ft_putendl("--end leaf--");
		return ;
	}
//	ft_putendl("cmd : ");
//	ft_putendl(tree->cmd);
//	ft_putendl("op : ");
//	ft_putendl(tree->op);
//	ft_putendl("args : ");
//	ft_putendl(tree->args);
//	ft_putendl("--leaf right--");
	ft_printtree(tree->right);
//	ft_putendl("--leaf left--");
	ft_printtree(tree->left);
//	ft_putendl("--end tree--");
	free(tree->cmd);
	free(tree->op);
	free(tree->args);
	free(tree);
}

int	main(int argc, char **argv)
{
	(void)argc;
		ft_putendl(argv[1]);
		ft_check(argv[1]);
	return (0);
}
