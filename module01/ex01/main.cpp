/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:45:55 by phijano-          #+#    #+#             */
/*   Updated: 2023/04/26 11:37:58 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <stdlib.h>

void leaks(void)
{
	system("leaks Moarbrainz!");
}

int	main(void)
{
	Zombie *myFriends;

	myFriends = zombieHorde(10, "Hungry");
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Zombie " << i << std::endl;
		myFriends[i].announce();
	}
	delete[] myFriends;
	atexit(leaks);
	return 0;
}
