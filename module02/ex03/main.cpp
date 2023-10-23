/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:51:16 by phijano-          #+#    #+#             */
/*   Updated: 2023/05/23 12:02:12 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int	main(void)
{

	Point a(0.0, 0.0);
	Point b(4.0, 0.0);
	Point c(0.0, 5.0);

	Point point1(1.0, 1.0);
	Point point2(2.0, 2.0);
	Point point3(4.0, 0.0);
	Point point4(-2.0, 2.0);

	std::cout << "a: x=" << a.getX() << ", y=" << a.getY() << std::endl;
	std::cout << "b: x=" << b.getX() << ", y=" << b.getY() << std::endl;
	std::cout << "c: x=" << c.getX() << ", y=" << c.getY() << std::endl;

	std::cout << "point1: x=" << point1.getX() << ", y=" << point1.getY() << std::endl;

	if(bsp(a, b, c, point1))
		std::cout << "point1 is in" << std::endl;
	else
		std::cout << "point1 is out" << std::endl;

	std::cout << "point2: x=" << point2.getX() << ", y=" << point2.getY() << std::endl;

	if(bsp(a, b, c, point2))
		std::cout << "point2 is in" << std::endl;
	else
		std::cout << "point2 is out" << std::endl;

	std::cout << "point3: x=" << point3.getX() << ", y=" << point3.getY() << std::endl;

	if(bsp(a, b, c, point3))
		std::cout << "point3 is in" << std::endl;
	else
		std::cout << "point3 is out" << std::endl;

	std::cout << "point4: x=" << point4.getX() << ", y=" << point4.getY() << std::endl;

	if(bsp(a, b, c, point4))
		std::cout << "point4 is in" << std::endl;
	else
		std::cout << "point4 is out" << std::endl;

	return 0;
}
