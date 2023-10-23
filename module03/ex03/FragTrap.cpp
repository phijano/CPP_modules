/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:41:47 by phijano-          #+#    #+#             */
/*   Updated: 2023/06/05 11:22:05 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap Assignation operator called" << std::endl;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}


FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " High five guys!! 🙌" << std::endl;

}
