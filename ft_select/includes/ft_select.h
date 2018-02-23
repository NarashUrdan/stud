/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 21:17:33 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/23 08:50:49 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "../libft/libft.h"
# include <termios.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <term.h>
//# include <curse.h>
typedef struct	s_ar
{
	char		*name;
	int			ghost;
	int			cursor;
	int			select;
	struct s_ar	*next;
	struct s_ar *prev;
}				t_ar;

typedef struct	s_size
{
	int	st_row;
	int	st_col;
	int	sw_max;
	int sw_col;
}				t_size;

t_ar	*wait_input(t_ar *arg, struct termios *term, t_size size);
t_ar	*lst_first(char *name);
void	ft_exit(t_ar **arg, struct termios *term, int mode);
void	ft_rtn(t_ar *arg, struct termios *term);
void	ft_print(t_ar *arg, t_size size);
void	lst_new(t_ar **arg, char *name);
void	ft_getsize(t_ar *arg, t_size *size);
#endif
