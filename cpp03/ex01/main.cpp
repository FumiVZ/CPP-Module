/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:26:05 by vzuccare          #+#    #+#             */
/*   Updated: 2024/10/23 18:35:17 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap clap("Dummy");

	clap.Display();
	clap.attack("target");
	clap.takeDamage(1);
	clap.beRepaired(1);
	clap.takeDamage(15);
	clap.beRepaired(1);

	ScavTrap scav("Pierrick");
	scav.guardGate();
	scav.Display();
	scav.attack("target");
	scav.takeDamage(1);
	scav.beRepaired(1);
	scav.takeDamage(15);
	scav.beRepaired(1);
	scav.guardGate();
	return (0);
}