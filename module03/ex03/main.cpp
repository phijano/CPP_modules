/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:21:13 by phijano-          #+#    #+#             */
/*   Updated: 2023/06/05 11:13:58 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void leaks(void)
{
	system("leaks Nowitsweird!");
}

int main()
{
	DiamondTrap myTrap("Sparky");

	for (int i = 1; i < 102; i++)
		myTrap.attack("Donald");
	myTrap.takeDamage(2);
	myTrap.takeDamage(99);
	myTrap.takeDamage(2);
	myTrap.beRepaired(7);

	DiamondTrap myBestTrap("Fireprrrr");

	myBestTrap.highFivesGuys();
	for (int i = 1; i < 3; i++)
	{
		myBestTrap.takeDamage(3);
		myBestTrap.beRepaired(3);
	}
	myBestTrap.whoAmI();
//	atexit(leaks);
	return 0;
}
