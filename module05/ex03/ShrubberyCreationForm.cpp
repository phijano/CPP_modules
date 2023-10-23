/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:35:55 by phijano-          #+#    #+#             */
/*   Updated: 2023/07/14 12:53:24 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):AForm("Shrubbery creation", 145, 137)
{
	_target = target;
	//std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery creation", 145, 137)
{
	//std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other)
{
	//std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	//std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	_target = other._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	//std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	AForm::execute(executor);
	std::ofstream myWriteFile(_target + "_shrubbery");
	if (myWriteFile.is_open())
		myWriteFile << "*tree* *tree* *tree*" << std::endl;
	else
		std::cout << "Error opening " << _target + "_shrubbery" << std::endl;	
}
