/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 21:18:49 by jukuntzm          #+#    #+#             */
/*   Updated: 2018/02/19 08:32:44 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static struct termios	ft_get_env(void)
{
	char					*env;
	static struct termios	term;

	if ((env = getenv("TERM")) == NULL)
	{
		ft_putendl_fd("error", 2);
		exit(EXIT_FAILURE);
	}
	if (tgetent(NULL, env) < 1)
	{
		ft_putendl_fd("error", 2);
		exit(EXIT_FAILURE);
	}
	if (tcgetattr(0, &term) == -1)
	{
		ft_putendl_fd("error", 2);
		exit(EXIT_FAILURE);
	}
	return (term);
}

static	void	ft_term(struct termios term)
{
	term.c_lflag &= ~(ICANON); 
	term.c_lflag &= ~(ECHO); 
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	 if (tcsetattr(0, TCSADRAIN, &term) == -1)
		 exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	int		i;
	t_ar	*arg;
	t_ar	*arg2 = NULL;
	static struct termios	term;
	char	*res;
	
	if (argc == 1)
		return (0);
	term = ft_get_env();
	ft_term(term);
	arg = lst_first(argv[1]);
	i = 1;
	while (argv[++i])
		lst_new(&arg, arg2, argv[i]);
	while (1)
	{
		ft_print(arg);
		arg = wait_input(arg);
		if ((res = tgetstr("cl", NULL)) == NULL)
	    return (-1);
		ft_putstr(res);
	}
	return (0);
}
