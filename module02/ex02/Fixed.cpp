/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:47:14 by phijano-          #+#    #+#             */
/*   Updated: 2023/05/23 11:44:55 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed	&other)
{
	std::cout << "Assignation operator called" << std::endl;
	_value = other._value;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	_value = number << _fractionalsBits;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	_value = (int)(roundf(number * (1 << _fractionalsBits)));
}


std::ostream &operator<<(std::ostream &os, const Fixed &fix)
{
	os << fix.toFloat();
	return os;
}

int	Fixed::toInt(void) const
{
	return (_value >> _fractionalsBits);
}

float	Fixed::toFloat(void) const
{
	return ((float)(_value) / (float)(1 << _fractionalsBits));
}


void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

int	Fixed::getRawBits() const
{
	return _value;
}

bool Fixed::operator>(const Fixed	&other) const
{
	return _value > other.getRawBits();
}

bool Fixed::operator<(const Fixed	&other) const
{
	return _value < other.getRawBits();
}

bool Fixed::operator>=(const Fixed	&other) const
{
	return _value >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed	&other) const
{
	return _value <= other.getRawBits();
}

bool Fixed::operator==(const Fixed	&other) const
{
	return _value == other.getRawBits();
}

bool Fixed::operator!=(const Fixed	&other) const
{
	return _value != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed	&other) const
{
	Fixed temp;
	temp.setRawBits(_value + other.getRawBits());
	return temp;
}

Fixed Fixed::operator-(const Fixed	&other) const
{
	Fixed temp;
	temp.setRawBits(_value - other.getRawBits());
	return temp;
}

Fixed Fixed::operator*(const Fixed	&other) const
{
	Fixed temp;
	temp.setRawBits(((long)_value * (long)other.getRawBits()) >> _fractionalsBits);
	return temp;
}

Fixed Fixed::operator/(const Fixed	&other) const
{
	Fixed temp;
	temp.setRawBits(((long)_value << _fractionalsBits) / (long)other.getRawBits());
	return temp;
}

Fixed &Fixed::operator++()
{
	_value ++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	_value ++;
	return temp;
}

Fixed &Fixed::operator--()
{
	_value --;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	_value --;
	return temp;
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

