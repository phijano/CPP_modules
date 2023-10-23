/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:08:59 by phijano-          #+#    #+#             */
/*   Updated: 2023/04/27 10:54:32 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA
#define HUMANA

#include <iostream>
#include "Weapon.hpp"

class	HumanA
{
	public:
		HumanA(std::string name, Weapon &myWeapon);
		void	attack();

	private:
		std::string	_name;
		Weapon		&_weapon;
};

#endif
