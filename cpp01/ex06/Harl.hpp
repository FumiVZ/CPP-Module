/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:34:22 by vzuccare          #+#    #+#             */
/*   Updated: 2024/10/16 14:12:31 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>
#include <map>
class Harl
{
	public:
		Harl();
		~Harl();
		void complain(std::string level);
	private:
		void debug();
		void info();
		void warning();
		void error();
};

#endif