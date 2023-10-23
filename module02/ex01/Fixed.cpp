/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:25:31 by phijano-          #+#    #+#             */
/*   Updated: 2023/05/23 10:22:12 by phijano-         ###   ########.fr       */
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
	_value = other.getRawBits();
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
