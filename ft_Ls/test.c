/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 21:06:05 by jukuntzm          #+#    #+#             */
/*   Updated: 2017/12/27 22:42:26 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char **argv)
{
	DIR	*fd;
	struct dirent *bite;

	if (argc > 1)
	{
		fd = opendir(argv[1]);
		while ((bite = readdir(fd)) != NULL)
			printf("%s\n", bite->d_name);
	}
	return (0);
}
