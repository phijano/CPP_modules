/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:46:17 by phijano-          #+#    #+#             */
/*   Updated: 2023/04/26 10:49:54 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE
#define ZOMBIE

#include <iostream>

class Zombie
{
	public:
		Zombie();
		Zombie(std::string zombieName);
		~Zombie();
		void	announce(void);
		void	setName(std::string zombieName);

	private:

		std::string	_name;
};

Zombie *zombieHorde(int N, std::string name);

#endif
