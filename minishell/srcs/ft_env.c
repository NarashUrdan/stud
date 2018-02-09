/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 07:04:32 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/09 07:21:26 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_unsetenv(char **tab, char **env)
{
	char	**tmp;
	int		j;
	int		i;

	i = 0;
	j = 0;
	tmp = NULL;
	if (ft_nbarg(tab) > 2)
	{
		ft_putendl_fd("unsetenv : too many arguments", 2);
		return ;
	}
	while (env[i])
	{
		if (ft_strncmp(tab[1], env[i], ft_strlen(tab[1])) == 0)
			i++;
		tmp[j] = ft_strdup(env[i]);
		i++;
		j++;
	}
	i = 0;
	while (tmp[i])
	{
		free(env[i]);
		env[i] = ft_strdup(tmp[i]);
		i++;
	}
	env[i] = NULL;
	ft_freedoublearray(tmp);
}

void	ft_env(char **tab, char **env)
{
/*	if (ft_strcmp(tab[0], "setenv") == 0)
		ft_setenv(tab, env);
*/	if (ft_strcmp(tab[0], "unsetenv") == 0)
		ft_unsetenv(tab, env);
/*	if (ft_strcmp(tab[0], "env") == 0)
		ft_en(tab, env);
*/}
