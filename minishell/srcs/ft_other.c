/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 04:05:10 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/11 09:55:03 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_other(char **tab, char **env)
{
	pid_t	cpid;
	char	*path;
	int		i;
	int		status;
	i = 0;
	path = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			path = ft_strdup(env[i]);
		i++;
	}
	if (path == NULL)
		return ;
	free(path);
	path = ft_strdup("/bin/");
	path = ft_strjoinfree(path, tab[0], 1);
	cpid = fork();
	i = 0;
	if (cpid == -1)
	{
		ft_putstr_fd("Error process", 2);
		exit(EXIT_FAILURE);
	}
	else if (cpid == 0)
	{
	ft_print_words_tables(env);
	write(1, "\n", 1);
	ft_putendl(path);
		i = execve(path, tab, env);
		if (i == -1)
			ft_error(tab[0]);
	}
	free(path);
	wait(&status);
}
