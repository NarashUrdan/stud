/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 21:53:22 by jukuntzm          #+#    #+#             */
/*   Updated: 2019/10/18 22:24:44 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_H
#define PEON_H

#include "Victim.hpp"

class   Peon : public Victim {

    public :

        Peon(std::string name);
        Peon(Peon const & src);
        ~Peon(void);
        Peon &      operator=(Peon const & rhs);
        void        getPolymorphed(void) const;
	std::string get_name(void) const;
    private :

        std::string _name;
        std::string _poly;
};
std::ostream	&operator<<(std::ostream &o, Peon const &r);
#endif /* ifndef PEON_H */
