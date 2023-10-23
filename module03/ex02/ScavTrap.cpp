/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:44:26 by phijano-          #+#    #+#             */
/*   Updated: 2023/05/24 11:40:36 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

static bool	isWorking(std::string name, unsigned int hp, unsigned int ep)
{
	if (hp > 0 & ep > 0)
		return true;
	else if (hp == 0)
		std::cout << "ScavTrap " << name << " is already destroyed." << std::endl;
	else if (ep == 0)
		std::cout << "ScavTrap " << name << " dont have energy left." << std::endl;
	return false;
}

void	ScavTrap::attack(const std::string& target)
{
	if (isWorking(_name, _hitPoints, _energyPoints))
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "<< _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}

