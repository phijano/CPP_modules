/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:53:41 by phijano-          #+#    #+#             */
/*   Updated: 2023/05/26 10:21:41 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG
 #define DOG

#include <iostream>
#include "Animal.hpp"

class Dog: public Animal
{
	public:

		Dog();
		Dog(const Dog &Other);
		Dog &operator=(const Dog &Other);
		~Dog();

		void makeSound() const;
};

#endif
