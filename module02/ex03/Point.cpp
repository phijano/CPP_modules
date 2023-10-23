/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:33:28 by phijano-          #+#    #+#             */
/*   Updated: 2023/05/19 10:38:51 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(Fixed(0)), _y(Fixed(0))
{
}

Point::Point(const Point &other)
{
	*this = other;
}

Point &Point::operator=(const Point	&other)
{
	Fixed *tmpx = const_cast<Fixed*>(&_x);
	*tmpx = other._x;
	Fixed *tmpy = const_cast<Fixed*>(&_y);
	*tmpy = other._y;
	return *this;
}

Point::~Point()
{

}

Point::Point(const float x, const float y)
{
	Fixed *tmpx = const_cast<Fixed*>(&_x);
	*tmpx = Fixed(x);
	Fixed *tmpy = const_cast<Fixed*>(&_y);
	*tmpy = Fixed(y);
}

Fixed	Point::getX(void) const
{
	return _x;
}

Fixed	Point::getY(void) const
{
	return _y;
}

void Point::setX(Fixed const x)
{
	Fixed *tmpx = const_cast<Fixed*>(&_x);
	*tmpx = Fixed(x);
}

void Point::setY(Fixed const y)
{
	Fixed *tmpy = const_cast<Fixed*>(&_y);
	*tmpy = Fixed(y);
}

