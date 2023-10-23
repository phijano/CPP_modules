/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:00:10 by phijano-          #+#    #+#             */
/*   Updated: 2023/05/19 10:33:32 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT
#define POINT

#include <iostream>
#include "Fixed.hpp"

class Point
{
	public:

		Point();
		Point(const Point &Other);
		Point &operator=(const Point &Other);
		~Point();
		Point(const float x, const float y);
		Fixed	getX(void) const;
		Fixed	getY(void) const;
		void	setX(Fixed const x);
		void	setY(Fixed const y);


	private:

		Fixed const _x;
		Fixed const _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
