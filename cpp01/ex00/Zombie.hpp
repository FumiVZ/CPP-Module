/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:51:04 by vzuccare          #+#    #+#             */
/*   Updated: 2024/10/10 15:05:51 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>



class Zombie
{
public:
	Zombie(std::string name);
	~Zombie(void);
	void announce(void) const;
	

private:
	std::string _name;
};

void randomChump(std::string name);
Zombie	*newZombie(std::string name);

#endif