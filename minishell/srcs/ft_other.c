/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 04:05:10 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/13 08:11:58 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_pouet(char **env)
{
	int		i;
	char	*path;

	i = -1;
	path = NULL;
	while (env[++i])
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			path = ft_strsub(env[i], 5, ft_strlen(env[i]) - 5);
	return (path);
}

char	*ft_ch(char *tmp, char *str, char **multipath)
{
	char *path;

	if (tmp)
		free(tmp);
	path = ft_strdup(str);
	if (multipath == NULL)
	{
		multipath = (char **)malloc(sizeof(char *) * 2);
		multipath[0] = ft_strnew(0);
		multipath[1] = NULL;
	}
	if ((access(str, X_OK)) == 0)
	{
		free(multipath[0]);
		multipath[0] = ft_strnew(0);
		return (path);
	}
	free(path);
	return (NULL);
}

char	**ft_reallocnull(void)
{
	char	**tmp;

	tmp = (char **)malloc(sizeof(char *) * 2);
	tmp[0] = ft_strnew(0);
	tmp[1] = NULL;
	return (tmp);
}

char	*ft_checkpath(char *str, char **env, int i)
{
	char	*path;
	char	**multipath;

	path = ft_pouet(env);
	if ((multipath = ft_strsplit(path, ':')) == NULL)
		multipath = ft_reallocnull();
	path = ft_ch(path, str, multipath);
	if (path == NULL)
		path = ft_strjoinfree("/", str, 0);
	while (multipath[++i] != NULL)
	{
		multipath[i] = ft_strjoinfree(multipath[i], path, 1);
		if ((access(multipath[i], X_OK)) == 0)
		{
			free(path);
			path = ft_strdup(multipath[i]);
			ft_freedoublearray(multipath);
			return (path);
		}
	}
	ft_freedoublearray(multipath);
	free(path);
	ft_error(str);
	return (NULL);
}

void	ft_other(char **tab, char **env)
{
	pid_t	cpid;
	char	*path;
	int		i;

	i = 0;
	path = ft_checkpath(tab[0], env, -1);
	if (path == NULL)
		return ;
	cpid = fork();
	i = 0;
	if (cpid == -1)
	{
		free(path);
		ft_putstr_fd("Error process", 2);
		exit(EXIT_FAILURE);
	}
	else if (cpid == 0)
	{
		i = execve(path, tab, env);
		if (i == -1)
			ft_error(tab[0]);
	}
	if (path != NULL)
		free(path);
	wait(&cpid);
}
