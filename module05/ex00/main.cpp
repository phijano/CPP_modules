/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:26:03 by phijano-          #+#    #+#             */
/*   Updated: 2023/07/13 11:46:14 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

void leaks(void)
{
	system("leaks Mommy...");
}

int main()
{
	Bureaucrat pepe("Pepe", 12);
	Bureaucrat pepepaco(pepe);
	std::cout << pepe << pepepaco;

	try
	{
		Bureaucrat marcos("Marcos", -123);
	}
	catch (std::exception &except)
	{
		std::cout << except.what() << std::endl;
	}

	try
	{
		Bureaucrat leona("Leona", 151);
	}
	catch (std::exception &except)
	{
		std::cout << except.what() << std::endl;
	}

	Bureaucrat alex("Alex", 150);
	try
	{
		alex.downGrade();
	}
	catch (std::exception &except)
	{
		std::cout << except.what() << std::endl;
	}

	Bureaucrat felix("Felix", 1);
	try
	{
		felix.riseGrade();
	}
	catch (std::exception &except)
	{
		std::cout << except.what() << std::endl;
	}
	atexit(leaks);
	return 0;
}
