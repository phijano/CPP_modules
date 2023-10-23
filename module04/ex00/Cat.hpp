/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:54:02 by phijano-          #+#    #+#             */
/*   Updated: 2023/05/26 10:21:51 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT
 #define CAT

#include <iostream>
#include "Animal.hpp"

class Cat: public Animal
{
	public:

		Cat();
		Cat(const Cat &Other);
		Cat &operator=(const Cat &Other);
		~Cat();

		void makeSound() const;
};

#endif
