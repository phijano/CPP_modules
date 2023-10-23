/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:21:13 by phijano-          #+#    #+#             */
/*   Updated: 2023/06/05 10:54:40 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void leaks(void)
{
	system("leaks Serena,mylove!");
}

int main()
{
	ScavTrap myTrap("Sparky");

	for (int i = 1; i < 52; i++)
		myTrap.attack("Donald");
	myTrap.takeDamage(2);
	myTrap.takeDamage(99);
	myTrap.takeDamage(2);
	myTrap.beRepaired(7);

	ScavTrap myBestTrap("Fireprrr");
	myBestTrap.guardGate();
	for (int i = 1; i < 3; i++)
	{
		myBestTrap.takeDamage(3);
		myBestTrap.beRepaired(3);
	}
//	atexit(leaks);
	return 0;
}
