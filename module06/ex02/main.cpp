/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:00:25 by phijano-          #+#    #+#             */
/*   Updated: 2023/08/03 11:50:23 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			return new(A);
		break;
		case 1:
			return new(B);
		break;
		case 2:
			return new(C);
		break;
		default:
		break;
	}
	return NULL;
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void checkBase(Base &p)
{
	try
	{
		A pntA = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)pntA;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		B pntB = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)pntB;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		C pntC = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)pntC;
	}
	catch (std::exception &e)
	{
	}
}

void leaks(void)
{
	system("leaks identify");
}

int main(void)
{
	Base *pnt;
	std::srand(std::time(NULL));
	for (int i = 0; i < 10; i++)
	{
		pnt = generate();
		identify(pnt);
		checkBase(*pnt);
		delete pnt;
	}
	atexit(leaks);
	return 0;
}
