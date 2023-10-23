/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:36:01 by phijano-          #+#    #+#             */
/*   Updated: 2023/06/29 12:55:50 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	//std::cout << "Cure default constructor called" << std::endl;
	_type = "cure";
}

Cure::Cure(const Cure& other): AMateria("cure")
{
	//std::cout << "Cure copy constructor called" << std::endl;
	(void)other;
}

Cure& Cure::operator=(const Cure& other)
{
	//std::cout << "Cure assignation operator called" << std::endl;
	(void)other;
	return *this;
}

Cure::~Cure()
{
	//std::cout << "Cure destructor called" << std::endl;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "´s wounds *" << std::endl; 
}

AMateria *Cure::clone() const
{
	AMateria *cureClone = new Cure();
	return cureClone;
}
