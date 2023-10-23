/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:06:54 by phijano-          #+#    #+#             */
/*   Updated: 2023/05/24 11:33:19 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("_clap_name")
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;

}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap Assignation operator called" << std::endl;
	ClapTrap::_name = other.ClapTrap::_name;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}


DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << _name  << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(std::string target)
{
	ScavTrap::attack(target);
}
