/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 02:54:27 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/01/25 03:40:52 by jukuntzm         ###   ########.fr       */
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

char	**ft_rev(char **path);
char	**ft_att(char **path, t_ar *ar);
void	ft_kiwi(int i, char **multipath, t_ar *ar);
char	*ft_malloc(char *opath, char *path, char *str);
char	**ft_tpath(char **multipath);
int		ft_arl(char *name, struct stat buf);
int		ft_nbarg(char **multipath);
int		ft_tdir(char *path);
int		ft_open(char **multipath, t_ar *ar);
int		ft_tripath(char **multipath, t_ar *ar);
int		ft_path(char **arg, char **multipath, int i, t_ar *ar);
void	ft_error(char *str, char arg);
void	ft_error2(char *str);
#endif
