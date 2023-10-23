/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:54:50 by phijano-          #+#    #+#             */
/*   Updated: 2023/06/29 11:10:26 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog& other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_type = "Dog";
	_brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignation operator called" << std::endl;
	*_brain = *other._brain;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

void Dog::makeSound() const
{
	std::cout << "bark" << std::endl;
}
