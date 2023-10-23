/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:20:27 by phijano-          #+#    #+#             */
/*   Updated: 2023/05/19 10:25:24 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static bool isPointInPlane(Point const linePointA, Point const linePointB, Point const triangleP, Point const point)
{
	Fixed incX(linePointB.getX() - linePointA.getX());
	Fixed incY(linePointB.getY() - linePointA.getY());

	if (incX == Fixed(0))
		return ((triangleP.getX() > linePointA.getX() && point.getX() > linePointA.getX())
				|| (triangleP.getX() < linePointA.getX() && point.getX() < linePointA.getX()));

	Fixed incTriPX(triangleP.getX() - linePointA.getX());
	Fixed incTriPYInLine(incTriPX * incY/incX);
	Fixed incTriPY(triangleP.getY() - linePointA.getY());

	Fixed incPointX(point.getX() - linePointA.getX());
	Fixed incPointYInLine(incPointX * incY/incX);
	Fixed incPointY(point.getY() - linePointA.getY());

	return (incTriPY > incTriPYInLine && incPointY > incPointYInLine) || (incTriPY < incTriPYInLine && incPointY < incPointYInLine);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	return (isPointInPlane(a, b, c, point) && isPointInPlane(b, c, a, point) && isPointInPlane(a, c, b, point));
}
