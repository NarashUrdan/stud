/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 21:17:33 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/27 10:42:39 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "../libft/libft.h"
# include <termios.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <term.h>
# include <signal.h>
# include <stdio.h>

typedef struct	s_ar
{
	char		*name;
	int			value;
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
	int	sw_row;
}				t_size;

void			ft_left(t_ar **arg);
struct termios	ft_get_env(void);
void			ft_signal(void);
void			ft_term(struct termios *term);
void			ft_cont(struct termios *term);
void			ft_right(t_ar **arg);
t_ar			*ft_arrow(t_ar *arg, char *ret, t_size size);
t_ar			*wait_input(t_ar *arg, struct termios *term, t_size size);
t_ar			*lst_first(char *name);
void			ft_stop(struct termios *term);
void			ft_exit(t_ar **arg, struct termios *term, int mode);
void			ft_check_value(t_ar **arg, t_size size);
void			ft_rtn(t_ar *arg, struct termios *term);
void			ft_print(t_ar *arg, t_size size);
void			lst_new(t_ar **arg, char *name, t_size size);
void			ft_getsize(t_ar *arg, t_size *size);
void			ft_unterm(struct termios *term);

#endif
