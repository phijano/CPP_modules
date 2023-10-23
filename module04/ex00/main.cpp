/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:14:16 by phijano-          #+#    #+#             */
/*   Updated: 2023/06/29 12:16:17 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void leaks(void)
{
	system("leaks Polymorphism");
}

int main()
{
	std::cout << "*************BASIC TEST**********************" << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;

	std::cout << "*************WRONG CAT TEST**********************" << std::endl;

	const WrongAnimal* myWrongMeta = new WrongAnimal();
	const Animal* myDog = new Dog();
	const WrongAnimal* myWrongCat = new WrongCat();

	std::cout << myDog->getType() << " " << std::endl;
	std::cout << myWrongCat->getType() << " " << std::endl;
	myWrongCat->makeSound(); //will output the cat sound??? Nope :)
	myDog->makeSound();
	myWrongMeta->makeSound();

	delete myWrongMeta;
	delete myWrongCat;
	delete myDog;
	
	atexit(leaks);

	return 0;
}
