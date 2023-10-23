/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:20:12 by phijano-          #+#    #+#             */
/*   Updated: 2023/05/19 11:33:35 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP
#define CLAPTRAP

#include <iostream>

class	ClapTrap
{
	public:

		ClapTrap();
		ClapTrap(const ClapTrap &Other);
		ClapTrap &operator=(const ClapTrap &Other);
		~ClapTrap();
		ClapTrap(std::string name);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	protected:

		std::string	_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

#endif
