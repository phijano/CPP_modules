/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:22:45 by phijano-          #+#    #+#             */
/*   Updated: 2023/03/01 12:23:20 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::Contact(const Contact &other)
{
	*this = other;
}

Contact &Contact::operator=(const Contact &other)
{
	_firstName = other._firstName;
	_lastName = other._lastName;
	_nickname = other._nickname;
	_phoneNumber = other._phoneNumber;
	_darkestSecret = other._darkestSecret;
	return *this;
}

Contact::~Contact()
{
}

void Contact::setFirst(std::string first)
{
	_firstName = first;
}

void Contact::setLast(std::string last)
{
	_lastName = last;
}

void Contact::setNick(std::string nick)
{
	_nickname = nick;
}

void Contact::setPhone(std::string phone)
{
	_phoneNumber = phone;
}

void Contact::setSecret(std::string secret)
{
	_darkestSecret = secret;
}

std::string Contact::getFirst()
{
	return _firstName;
}

std::string Contact::getLast()
{
	return _lastName;
}

std::string Contact::getNick()
{
	return _nickname;
}

std::string Contact::getPhone()
{
	return _phoneNumber;
}

std::string Contact::getSecret()
{
	return _darkestSecret;
}
