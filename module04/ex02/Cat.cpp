/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:55:07 by phijano-          #+#    #+#             */
/*   Updated: 2023/06/29 11:11:03 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat& other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	_type = "Cat";
	_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignation operator called" << std::endl;
	*_brain = *other._brain;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

void Cat::makeSound() const
{
	std::cout << "meow" << std::endl;
}
