/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:12:18 by vzuccare          #+#    #+#             */
/*   Updated: 2024/11/12 18:20:21 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap: " << name << " created!" << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	this->Display();
}
ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap: " << this->_name << " destroyed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return (*this);
}

void ClapTrap::attack(std::string const &target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "ClapTrap: " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap: " << this->_name << " can't attack he is already dead or you don't have any energy left!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int amount2 = amount;
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		while (amount2-- > 0 && this->_hitPoints > 0)
			this->_hitPoints--;
		std::cout << "ClapTrap: " << this->_name << " takes " << amount << " points of damage!" << std::endl;
		return;
 	}
	std::cout << "ClapTrap: " << this->_name << " is already dead!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	unsigned int amount2 = amount;
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		while (amount2-- > 0 && this->_hitPoints < UINT_MAX && this->_energyPoints > 0)
		{
			this->_hitPoints++;
			this->_energyPoints--;
		}
		std::cout << "ClapTrap: " << this->_name << " has been repaired for " << amount << " hit points!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap: " << this->_name << " can't be repaired, is already dead or you don't have any energy left!" << std::endl;
}

void ClapTrap::Display(void)
{
	std::cout << "ClapTrap: " << this->_name << " stats: " << this->_hitPoints << " hit points, " << this->_energyPoints << " energy points, " << this->_attackDamage << " attack damage." << std::endl; 
}