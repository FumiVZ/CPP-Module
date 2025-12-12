/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:38:18 by vzuccare          #+#    #+#             */
/*   Updated: 2024/10/30 09:27:51 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cerr << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cerr << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &src)
{
	std::cerr << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal::~Animal(void)
{
	std::cerr << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	std::cerr << "Animal assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	this->_type = src._type;
	return *this;
}

std::string Animal::getType(void) const
{
	return this->_type;
}
