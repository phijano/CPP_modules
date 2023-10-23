/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:22:15 by phijano-          #+#    #+#             */
/*   Updated: 2023/08/22 11:17:43 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include <vector>
#include <list>

int randomNumber()
{
	return std::rand() % 1000000000;
}


int main(void)
{
	std::list<int> myList(10000);
	std::srand (unsigned(std::time(0)));
	std::generate(myList.begin(), myList.end(), randomNumber);
	for (std::list<int>::iterator it = myList.begin(); it !=  myList.end(); it++)
		std::cout << *it << std::endl;
	Span bigSpan(10000);
	try
	{
		bigSpan.addNumber(myList.begin(), myList.end());
		std::cout << "******10000 Numbers spans" << std::endl;
		std::cout << bigSpan.shortestSpan() << std::endl;
		std::cout << bigSpan.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "******Example test" << std::endl;	
	Span sp = Span(5);
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "******Exceptions tests" << std::endl;

	Span noRoomSpan;
	try
	{
		noRoomSpan.addNumber(12);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	Span other = Span(3);
	int myints[] = {-16,2,77,29};
	std::vector<int> myVector(myints, myints + sizeof(myints) / sizeof(int));
	try
	{
		other.addNumber(myVector.begin(), myVector.end());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << other.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << other.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
