/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:17:02 by phijano-          #+#    #+#             */
/*   Updated: 2023/07/13 12:14:44 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class AForm::GradeTooHighException: public std::exception
{
	const char * what () const throw ()
	{
		return "Grade too high";
	}
};

class AForm::GradeTooLowException: public std::exception
{
	const char * what () const throw ()
	{
		return "Grade too low";
	}
};

class AForm::NotSignedException: public std::exception
{
	const char * what () const throw ()
	{
		return "Form is not signed";
	}
};

AForm::AForm(const std::string &name, const short &gradeToSign, const short &gradeToExecute): _name(name), _signed(false),
	_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	//std::cout << "AForm constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(): _name("Default"), _signed(false), _gradeToSign(1), _gradeToExecute(1)
{
	//std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const AForm& other): _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	//std::cout << "AForm copy constructor called" << std::endl;
	*this = other;
}

AForm& AForm::operator=(const AForm& other)
{
	//std::cout << "AForm assignation operator called" << std::endl;
	_signed = other._signed;
	return *this;
}

AForm::~AForm()
{
	//std::cout << "AForm destructor called" << std::endl;
}

std::string const &AForm::getName() const
{
	return _name;
}

const bool &AForm::getSigned() const
{
	return _signed;
}

const short &AForm::getGradeToSign() const
{
	return _gradeToSign;
}

const short &AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}


void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
		_signed = true;
	else
		throw AForm::GradeTooLowException();
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!_signed)
		throw AForm::GradeTooLowException();
	else if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << form.getName();
	if (form.getSigned())
		os << ", AForm signed, grade to sign ";
	else
		os << ", AForm not signed, grade to sign ";
	os << form.getGradeToSign() << ", grade to execute " << form.getGradeToExecute() << std::endl;
	return os;
}
