/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 02:54:27 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/01/19 05:25:44 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <sys/stat.h> 
# include <sys/types.h>
# include <dirent.h>
# include <string.h>
# include <unistd.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include "../libft/libft.h"
# include <errno.h>  
# include <stdio.h>
typedef struct s_lst
{
	int				dor;
	char			*name;
	struct stat		buf;
}				t_lst;

typedef struct s_ar
{
	int	a;
	int	r;
	int	re;
	int	l;
	int	t;
}				t_ar;

void	ft_error(char *str, char arg);
#endif
