/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:20:39 by phijano-          #+#    #+#             */
/*   Updated: 2023/05/19 11:55:35 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

static bool	isWorking(std::string name, unsigned int hp, unsigned int ep)
{
	if (hp > 0 & ep > 0)
		return true;
	else if (hp == 0)
		std::cout << "ClapTrap " << name << " is already destroyed." << std::endl;
	else if (ep == 0)
		std::cout << "ClapTrap " << name << " dont have energy left." << std::endl;
	return false;
}

void	ClapTrap::attack(const std::string& target)
{
	if (isWorking(_name, _hitPoints, _energyPoints))
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "<< _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
		if (_hitPoints <= amount)
		{
			_hitPoints = 0;
			std::cout << "ClapTrap " << _name <<  " is destroyed " << std::endl;
		}
		else
		{
			_hitPoints -= amount;
			std::cout << "ClapTrap " << _name << " has " << _hitPoints << " hitpoints left." << std::endl;
		}
	}
	else
		std::cout << "ClapTrap " << _name  << " is already destroyed" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (isWorking(_name, _hitPoints, _energyPoints))
	{
		std::cout << "ClapTrap " << _name << " recover " << amount << " hit points!" << std::endl;
		_hitPoints += amount;
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " has " << _hitPoints << " hitpoints left." << std::endl;
	}
}
