/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:33:41 by phijano-          #+#    #+#             */
/*   Updated: 2023/07/17 10:19:05 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	//std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	//std::cout << "Intern copy constructor called" << std::endl;
	*this = other;
}

Intern& Intern::operator=(const Intern& other)
{
	//std::cout << "Intern assignation operator called" << std::endl;
	(void)other;
	return *this;
}

Intern::~Intern()
{
	//std::cout << "Intern destructor called" << std::endl;
}

static AForm *shrubberyCreation(std::string target)
{
	return new ShrubberyCreationForm(target);
}

static AForm *robotomyRequest(std::string target)
{
	return new RobotomyRequestForm(target);
}

static AForm *presidentialPardon(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};	
	AForm *(*forms[])(std::string) = {&shrubberyCreation, &robotomyRequest, &presidentialPardon};

	std::string temp(name);
	for (unsigned int i = 0 ; i < temp.size(); i++)
		temp[i] = tolower(temp[i]);

	for (unsigned int i = 0; i < 3; i++)
	{
		if (temp == names[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return forms[i](target);
		}
	}
	std::cout << "Intern couldnt find " << name << std::endl;
	return NULL;
}
