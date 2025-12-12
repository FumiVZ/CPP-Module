/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:38:24 by vzuccare          #+#    #+#             */
/*   Updated: 2024/10/29 18:56:13 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
public:
	Animal();
	Animal(std::string type);
	Animal(const Animal &src);
	virtual ~Animal(void);
	Animal &operator=(const Animal &src);
	std::string getType(void) const;
	virtual void makeSound(void) const;
protected:
	std::string _type;
};

#endif