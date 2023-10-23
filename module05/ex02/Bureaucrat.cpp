/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:10:49 by phijano-          #+#    #+#             */
/*   Updated: 2023/07/13 12:21:40 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat::GradeTooHighException: public std::exception
{
	const char * what () const throw ()
	{
		return "Grade too high";
	}
};

class Bureaucrat::GradeTooLowException: public std::exception
{
	const char * what () const throw ()
	{
		return "Grade too low";
	}
};

Bureaucrat::Bureaucrat(const std::string &name, const short &grade): _name(name)
{
	//std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150)
{
	//std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name)
{
	//std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	//std::cout << "Bureaucrat assignation operator called" << std::endl;
	_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	//std::cout << "Bureaucrat destructor called" << std::endl;
}

const std::string &Bureaucrat::getName() const
{
	return _name;
}

const short &Bureaucrat::getGrade() const
{
	return _grade;
}


void Bureaucrat::riseGrade()
{
	if (_grade > 1)
		_grade--;
	else
		throw GradeTooHighException();
}

void Bureaucrat::downGrade()
{
	if (_grade < 150)
		_grade++;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return os;
}

void Bureaucrat::signForm(AForm &myForm)
{
	try
	{
		myForm.beSigned(*this);
		std::cout << getName() << " signed " << myForm.getName() << std::endl;
	}
	catch (std::exception &except)
	{
		std::cout << getName() << " couldn't sign " << myForm.getName() << " because it needs a higher grade." << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &except)
	{
		std::cout << getName() << " couldn't sign " << form.getName() << " because " << except.what() << std::endl;
	}
}
