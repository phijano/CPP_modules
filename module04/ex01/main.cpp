/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:14:16 by phijano-          #+#    #+#             */
/*   Updated: 2023/06/29 13:17:37 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void leaks(void)
{
	system("leaks Idon’twanttosettheworldonfire");
}

int main()
{
	std::cout << "*************BASIC TEST**********************" << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete j;	
	delete i;

	std::cout << "*************ANIMAL ARRAY TEST**********************" << std::endl;

	Animal	*myFriends[4];

	std::cout <<  "*************FILLING ARRAY**********************"<< std::endl;

	for (int index = 0; index < 4; index++)
	{
		if (index % 2 == 0)
			myFriends[index] = new Dog();
		else
			myFriends[index] = new Cat();
		myFriends[index]->makeSound();
	}

	std::cout << "*************DELETING ARRAY**********************" << std::endl;

	for (int index = 0; index < 4; index++)
	{
		myFriends[index]->makeSound();
		delete myFriends[index];
	}
	
	std::cout << "*************DEEP COPY TEST**********************" << std::endl;
	
	Cat *k = new Cat();
	Cat *l = new Cat(*k);

	Cat *m = new Cat();
	*m = *k;

	delete k;
	delete l;
	delete m;

	Dog *n = new Dog();
	Dog *o = new Dog(*n);

	Dog *p = new Dog();
	*p = *n;

	delete n;
	delete o;
	delete p;

	atexit(leaks);
	return 0;
}
