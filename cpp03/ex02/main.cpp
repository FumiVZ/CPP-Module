/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:26:05 by vzuccare          #+#    #+#             */
/*   Updated: 2024/11/12 18:22:09 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap clap("Dummy");

	clap.attack("target");
	clap.takeDamage(1);
	clap.beRepaired(1);
	clap.takeDamage(15);
	clap.beRepaired(1);

	ScavTrap scav("Pierrick");
	scav.guardGate();
	scav.attack("target");
	scav.takeDamage(1);
	scav.beRepaired(1);
	scav.takeDamage(15);
	scav.beRepaired(1);
	scav.guardGate();

	FragTrap frag("Lionnelle");
	frag.highFivesGuys();
	frag.attack("target");
	frag.takeDamage(1);
	frag.beRepaired(1);
	frag.takeDamage(15);
	frag.beRepaired(1);
	frag.highFivesGuys();
	return (0);
}