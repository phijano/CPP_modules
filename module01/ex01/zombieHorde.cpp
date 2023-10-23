/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:46:58 by phijano-          #+#    #+#             */
/*   Updated: 2023/04/26 10:18:30 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *myFriends;

	myFriends = new Zombie[N];
	for (int i = 0; i < N; i++)
		myFriends[i].setName(name);
	return myFriends;
}
