/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:40:06 by phijano-          #+#    #+#             */
/*   Updated: 2023/07/13 12:17:36 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

class Form::GradeTooHighException: public std::exception
{
	const char * what () const throw ()
	{
		return "Grade too high";
	}
};

class Form::GradeTooLowException: public std::exception
{
	const char * what () const throw ()
	{
		return "Grade too low";
	}
};

Form::Form(const std::string &name, const short &gradeToSign, const short &gradeToExecute): _name(name), _signed(false), 
	_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	//std::cout << "Form constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(): _name("Default"), _signed(false), _gradeToSign(1), _gradeToExecute(1)
{
	//std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const Form& other): _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	//std::cout << "Form copy constructor called" << std::endl;
	*this = other;
}

Form& Form::operator=(const Form& other)
{
	//std::cout << "Form assignation operator called" << std::endl;
	_signed = other._signed;
	return *this;
}

Form::~Form()
{
	//std::cout << "Form destructor called" << std::endl;
}

std::string const &Form::getName() const
{
	return _name;
}

const bool &Form::getSigned() const
{
	return _signed;
}

const short &Form::getGradeToSign() const
{
	return _gradeToSign;
}

const short &Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
		_signed = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << form.getName();
	if (form.getSigned())
		os << ", Form signed, grade to sign ";
	else
		os << ", Form not signed, grade to sign ";
	os << form.getGradeToSign() << ", grade to execute " << form.getGradeToExecute() << std::endl;
	return os;
}
