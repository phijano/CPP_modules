/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:38:25 by phijano-          #+#    #+#             */
/*   Updated: 2023/04/25 10:49:48 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Zombie.hpp"

int main(void)
{
	Zombie *myFriend;
	
	std::cout << "zombie using stack memory" << std::endl;
	randomChump("peperoni");
	std::cout << "zombie using heap memory" << std::endl;
	myFriend = newZombie("pipas");
	myFriend->announce();
	delete(myFriend);
	return 0;
}
