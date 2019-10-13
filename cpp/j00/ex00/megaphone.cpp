/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:59:36 by jukuntzm          #+#    #+#             */
/*   Updated: 2019/10/13 16:15:36 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int main(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    else {
        while (i < argc) {
            j = 0;
            while (argv[i][j] != '\0') {
                std::cout << (char)ft_toupper((int)argv[i][j]);
                j++;
            }
            i++;
        }
        std::cout << std::endl;
    }
    return 0;
}
