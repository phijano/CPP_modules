/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:07:24 by phijano-          #+#    #+#             */
/*   Updated: 2023/05/24 11:19:26 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP
#define DIAMONDTRAP

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap: public ScavTrap, public FragTrap
{
	public:

		DiamondTrap();
		DiamondTrap(const DiamondTrap &Other);
		DiamondTrap &operator=(const DiamondTrap &Other);
		~DiamondTrap();
		DiamondTrap(std::string name);
		void attack(std::string target);
		void whoAmI();

	private:

		std::string	_name;
};

#endif
