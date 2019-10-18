/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 20:03:25 by jukuntzm          #+#    #+#             */
/*   Updated: 2019/10/18 22:23:38 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_H
#define VICTIM_H

#include <iostream>
#include <string>

class   Victim {

    public :

        Victim(std::string name);
        Victim(Victim const & src);
        ~Victim(void);
        Victim &    operator=(Victim const & rhs);
        std::string get_name(void) const;
        virtual void        getPolymorphed() const;

    private :

        std::string _name;
        std::string _poly;
};
std::ostream &  operator<<(std::ostream & o, const Victim & rhs);
#endif
