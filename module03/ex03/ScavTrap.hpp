/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:22:52 by phijano-          #+#    #+#             */
/*   Updated: 2023/05/22 12:11:55 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP
#define SCAVTRAP

#include <iostream>
#include "ClapTrap.hpp"

class	ScavTrap: virtual public ClapTrap
{
	public:

		ScavTrap();
		ScavTrap(const ScavTrap &Other);
		ScavTrap &operator=(const ScavTrap &Other);
		~ScavTrap();
		ScavTrap(std::string name);
		void	attack(const std::string &target);
		void	guardGate();
};

#endif
