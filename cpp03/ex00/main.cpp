/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:26:05 by vzuccare          #+#    #+#             */
/*   Updated: 2024/11/12 18:14:21 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap("Dummy");

	clap.Display();
	clap.attack("target");
	clap.takeDamage(1);
	clap.beRepaired(1);
	clap.takeDamage(20);
	clap.Display();
	clap.beRepaired(1);
	return (0);
}