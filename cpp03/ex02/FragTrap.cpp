/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:01:12 by vzuccare          #+#    #+#             */
/*   Updated: 2024/11/12 18:21:14 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap: " << name << " created!" << std::endl;
	
}
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap: " << this->_name << " is dead!" << std::endl;
}
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap: " << this->_name << " high fives guys!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return (*this);
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	*this = src;
}