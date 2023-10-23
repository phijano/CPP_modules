/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:35:38 by phijano-          #+#    #+#             */
/*   Updated: 2023/04/24 12:18:08 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE
#define ZOMBIE

#include <iostream>

class Zombie
{
	public:
		Zombie(std::string zombieName);
		~Zombie();
		void	announce(void);

	private:
		std::string	_name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
