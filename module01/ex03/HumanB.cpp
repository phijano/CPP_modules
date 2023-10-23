/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:09:29 by phijano-          #+#    #+#             */
/*   Updated: 2023/04/27 11:18:51 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;
}

void	HumanB::setWeapon(Weapon &myWeapon)
{
	_weapon = &myWeapon;
}

void	HumanB::attack()
{
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
