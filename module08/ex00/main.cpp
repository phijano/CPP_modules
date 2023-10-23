/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:59:47 by phijano-          #+#    #+#             */
/*   Updated: 2023/08/18 13:35:41 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include "easyfind.hpp"

int main(void)
{
//	std::list<int> myCont;
	std::vector<int> myCont;
	
	for (int i = 0; i < 10; i++)
		if (i == 8)
			myCont.push_back(4);
		else
			myCont.push_back(i);

	std::cout << "Container" << std::endl;

//	for (std::list<int>::iterator i = myCont.begin(); i != myCont.end(); i++)
	for (std::vector<int>::iterator i = myCont.begin(); i != myCont.end(); i++)
		std::cout << *i << std::endl;

	try
	{
		std::cout << "Is 4 in container?" << std::endl;
		std::cout << *easyfind(myCont, 4) << std::endl;
		std::cout << "Testing deleting the first ocurrence of 4" << std::endl;
		myCont.erase(easyfind(myCont, 4));
		std::cout << "Deleted" << std::endl;

	}
	catch (std::exception &except)
	{
		std::cout << except.what() << std::endl;
	}
	std::cout << "Container after delete the first ocurrence of 4" << std::endl;

//	for (std::list<int>::iterator i = myCont.begin(); i != myCont.end(); i++)
	for (std::vector<int>::iterator i = myCont.begin(); i != myCont.end(); i++)
		std::cout << *i << std::endl;

	try
	{
		std::cout << "Is -453 in container?" << std::endl;
		std::cout << *easyfind(myCont, -453) << std::endl;
	}
	catch (std::exception &except)
	{
		std::cout << except.what() << std::endl;
	}

	return 0;
}
