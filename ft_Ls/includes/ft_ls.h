/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 02:54:27 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/01/17 05:26:23 by jukuntzm         ###   ########.fr       */
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

typedef struct s_lst
{
	struct dirent	*dir;
	struct stat		buf;
	struct passwd	*uid;
	struct group	*bite;
	char			*merde;
	struct t_lst	*next;
}				t_lst;

typedef struct s_ar
{
	int	a;
	int	r;
	int	re;
	int	l;
	int	t;
}				t_ar;

int		ft_open(char *path, t_ar ar);
int		ft_arl(char *path, t_lst files);
int		ft_l(t_lst *lst, struct dirent *zob);
int		ft_path(char *ar);

#endif
