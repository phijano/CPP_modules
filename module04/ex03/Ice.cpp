/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:22:42 by phijano-          #+#    #+#             */
/*   Updated: 2023/06/29 12:55:13 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	//std::cout << "Ice default constructor called" << std::endl;
	_type = "ice";
}

Ice::Ice(const Ice& other): AMateria("Ice")
{
	//std::cout << "Ice copy constructor called" << std::endl;
	(void)other;
}

Ice& Ice::operator=(const Ice& other)
{
	//std::cout << "Ice assignation operator called" << std::endl;
	(void)other;
	return *this;
}

Ice::~Ice()
{
	//std::cout << "Ice destructor called" << std::endl;
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shot an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria *Ice::clone() const
{
	AMateria *iceClone = new Ice();
	return iceClone;
}
