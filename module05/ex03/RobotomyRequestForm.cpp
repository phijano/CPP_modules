/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:22:48 by phijano-          #+#    #+#             */
/*   Updated: 2023/07/14 13:00:21 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):AForm("Robotomy request", 72, 45)
{
	_target = target;
	//std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy request", 72, 45)
{
	//std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other)
{
	//std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	//std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
	_target = other._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	//std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	AForm::execute(executor);
	std::cout << "*drill noises*" << std::endl;
	std::srand(std::time(NULL));
	if (rand() % 2)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}
