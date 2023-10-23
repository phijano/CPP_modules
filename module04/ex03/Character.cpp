/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:43:07 by phijano-          #+#    #+#             */
/*   Updated: 2023/06/29 12:38:02 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name): _name(name)
{
	//std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(): _name("Anonymous")
{
	//std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& other)
{
	//std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	_name = other._name;
}

Character& Character::operator=(const Character& other)
{
	//std::cout << "Character assignation operator called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	_name = other._name;
	return *this;
}

Character::~Character()
{
	//std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
}

std::string const &Character::getName() const
{
	return _name;
}


void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (_inventory[idx])
		_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (_inventory[idx])
		_inventory[idx]->use(target);
}
