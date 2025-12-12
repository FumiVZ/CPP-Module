/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:51:04 by vzuccare          #+#    #+#             */
/*   Updated: 2024/10/10 15:30:18 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>



class Zombie
{
public:
	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);
	void announce(void) const;
	

private:
	std::string _name;
};

Zombie	*newZombie(std::string name);
Zombie	*zombieHorde( int N, std::string name );

#endif