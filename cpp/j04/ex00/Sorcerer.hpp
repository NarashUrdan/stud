/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:02:27 by jukuntzm          #+#    #+#             */
/*   Updated: 2019/10/18 20:30:34 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_H
#define SORCERER_H

#include <iostream>
#include <string>
#include "Victim.hpp"

class   Sorcerer {

    public :

        //Sorcerer(void);
        Sorcerer(std::string name, std::string title);
        Sorcerer(Sorcerer const & src);
        ~Sorcerer(void);
        Sorcerer &  operator=(Sorcerer const & rhs);
        std::string get_name(void) const;
        std::string get_title(void) const;
        void polymorph(Victim const &v) const; 
    
    private :

        std::string _name;
        std::string  _title;

};

std::ostream &  operator<<(std::ostream & o, const Sorcerer & rhs);
#endif
