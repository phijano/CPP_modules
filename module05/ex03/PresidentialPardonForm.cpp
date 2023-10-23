/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:24:13 by phijano-          #+#    #+#             */
/*   Updated: 2023/07/14 12:31:39 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):AForm("Presidential pardon", 25, 5)
{
	_target = target;
	//std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential pardon", 25, 5)
{
	//std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other)
{
	//std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	//std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
	_target = other._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	//std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	AForm::execute(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
