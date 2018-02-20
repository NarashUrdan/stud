/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 21:17:33 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/20 10:41:46 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "../libft/libft.h"
# include <termios.h>
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

t_ar	*wait_input(t_ar *arg);
t_ar	*lst_first(char *name);
void	ft_print(t_ar *arg);
void	lst_new(t_ar **arg, t_ar *arg2, char *name);
#endif
