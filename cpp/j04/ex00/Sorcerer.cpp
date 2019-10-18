/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukuntzm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:02:36 by jukuntzm          #+#    #+#             */
/*   Updated: 2019/10/18 20:30:35 by jukuntzm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

/*Sorcerer::Sorcerer(void){
    this->_name = "About";
    this->_title = "Blank";
    std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
}*/

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title) {
    std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const & src):_name(src._name), _title(src._title) {
    *this = src;
}

Sorcerer::~Sorcerer(void){
    std::cout << this->_name <<", "<<this->_title << ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer &  Sorcerer::operator=(Sorcerer const & rhs){
    this->_name = rhs._name;
    this->_title = rhs._title;
    return *this;
}

std::string Sorcerer::get_title(void) const{
    return(this->_title);
}

std::string Sorcerer::get_name(void) const{
    return(this->_name);
}

void    Sorcerer::polymorph(Victim const &v)const {
    return(v.getPolymorphed());
}

std::ostream &   operator<<(std::ostream & o, const Sorcerer & rhs){
    o << "I am" << rhs.get_name() << ", "<< rhs.get_title() << ", and I like ponies ! "<< std::endl;
    return o;
}
