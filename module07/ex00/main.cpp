/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:36:04 by phijano-          #+#    #+#             */
/*   Updated: 2023/08/11 10:37:20 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main( void ) 
{
	int a = 2;
	int b = 3;

	std::cout << "subject tests" << std::endl;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	
	std::string c = "chaine1";
	std::string d = "chaine2";
	
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << "other tests" << std::endl;


	float e = -0.9f;
	float f = 0.3f;


	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "swap" << std::endl;
	::swap(e, f);
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;

	double g = 1123.91;
	double h = 1123.96;


	std::cout << "g = " << g << ", h = " << h << std::endl;
	std::cout << "swap" << std::endl;
	::swap(g, h);
	std::cout << "g = " << g << ", h = " << h << std::endl;
	std::cout << "min( g, h ) = " << ::min( g, h ) << std::endl;
	std::cout << "max( g, h ) = " << ::max( g, h ) << std::endl;

	return 0;
}
