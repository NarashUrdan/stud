/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 22:09:51 by jukuntzm          #+#    #+#             */
/*   Updated: 2019/10/18 22:24:44 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon(std::string name): Victim(name){
    this->_poly = " has been turned into a cute little sheep !";
    this->_name = name;
    std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const & src): Victim(src){
    *this = src;
}

Peon::~Peon(void){
    std::cout << "Bleuark..." << std::endl;
}

Peon &    Peon::operator=(Peon const & rhs){
    this->_name = rhs._name;
    return *this;
}
/* 
std::ostream &   operator<<(std::ostream & o, const Peon & rhs){
    o << "I am" << rhs.get_name() << ", and I like otters ! "<< std::endl;
    return o;
}*/
