/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 20:10:28 by jukuntzm          #+#    #+#             */
/*   Updated: 2019/10/18 22:24:44 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim(std::string name): _name(name){
    std::cout << "Some random victim called "<< this->_name <<" just popped !" << std::endl;
    this->_poly = " has been turned into a cute little sheep !";
}

Victim::Victim(Victim const & src){
    *this = src;
}

Victim::~Victim(void){
    std::cout << "Victim "<< this->_name <<" just died for no apparent reason !" << std::endl;
}

Victim &    Victim::operator=(Victim const & rhs){
    this->_name = rhs._name;
    return *this;
}

std::string Victim::get_name(void) const {
    return(this->_name);
}

void	Victim::getPolymorphed(void) const{
    std::cout << this->_name << this->_poly << std::endl;
}

std::ostream &   operator<<(std::ostream & o, const Victim & rhs){
    o << "I am " << rhs.get_name() << ", and I like otters ! "<< std::endl;
    return o;
}
