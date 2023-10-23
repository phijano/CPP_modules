/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:32:16 by phijano-          #+#    #+#             */
/*   Updated: 2023/06/29 13:01:49 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type): _type(type)
{
	//std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria()
{
	//std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
	//std::cout << "AMateria copy constructor called" << std::endl;
	(void)other;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	//std::cout << "AMateria assignation operator called" << std::endl;
	(void)other;	
	return *this;
}

AMateria::~AMateria()
{
	//std::cout << "AMateria destructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "* " << _type << " do something to " << target.getName() << " *" << std::endl; 
}
