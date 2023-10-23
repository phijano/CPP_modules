/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:09:20 by phijano-          #+#    #+#             */
/*   Updated: 2023/04/27 11:19:03 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB
#define HUMANB

#include <iostream>
#include "Weapon.hpp"

class	HumanB
{
	public:
		HumanB(std::string name);
		void	setWeapon(Weapon &myWeapon);
		void	attack();

	private:
		std::string	_name;
		Weapon		*_weapon;
};

#endif
