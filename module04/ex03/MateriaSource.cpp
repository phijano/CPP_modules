/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:42:31 by phijano-          #+#    #+#             */
/*   Updated: 2023/06/28 12:46:37 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	//std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	//std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
	//std::cout << "MateriaSource assignation operator called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	//std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
}

void MateriaSource::learnMateria(AMateria* mat)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = mat;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
		if (_inventory[i]->getType() == type)
			return (_inventory[i]->clone());
	return (0);
}
