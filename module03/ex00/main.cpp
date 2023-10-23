/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:53:43 by phijano-          #+#    #+#             */
/*   Updated: 2023/06/05 10:27:41 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void leaks(void)
{
	system("leaks Aaaaand...OPEN!");
}

int main()
{
	ClapTrap myTrap("Sparky");

	for (int i = 1; i < 13; i++)
		myTrap.attack("Dog");
	myTrap.takeDamage(2);
	myTrap.takeDamage(20);
	myTrap.takeDamage(2);
	myTrap.beRepaired(7);

	ClapTrap myBestTrap("Fireprrr");
	for (int i = 1; i < 15; i++)
	{
		myBestTrap.takeDamage(3);
		myBestTrap.beRepaired(3);

	}
	//atexit(leaks);
	return 0;
}
