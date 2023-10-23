/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:26:03 by phijano-          #+#    #+#             */
/*   Updated: 2023/07/17 09:48:58 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void leaks(void)
{
	system("leaks Form...");
}

int main()
{

	try
	{
		Form MyForm("Crap Form", 0, 75);
	}
	catch (std::exception &except)
	{
		std::cout << except.what() << std::endl;
	}

	try
	{
		Form MyForm("Crap Form", 3245, 75);
	}
	catch (std::exception &except)
	{
		std::cout << except.what() << std::endl;
	}
	try
	{
		Form MyForm("Crap Form", 130, 0);
	}
	catch (std::exception &except)
	{
		std::cout << except.what() << std::endl;
	}
	try
	{
		Form MyForm("Crap Form", 130, 32453);
	}
	catch (std::exception &except)
	{
		std::cout << except.what() << std::endl;
	}

	Bureaucrat pepe("Pepe", 122);
	Form MyForm("Film production request", 130, 75);
	Form MyMustDoForm("Lottery winner request", 11, 75);
	std::cout << pepe << MyForm << MyMustDoForm;

	pepe.signForm(MyForm);
	try
	{
		pepe.signForm(MyMustDoForm);
	}
	catch (std::exception &except)
	{
		std::cout << except.what() << std::endl;
	}

	atexit(leaks);
	return 0;
}
