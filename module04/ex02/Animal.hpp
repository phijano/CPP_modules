/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:53:25 by phijano-          #+#    #+#             */
/*   Updated: 2023/06/21 11:55:46 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL
 #define ANIMAL

#include <iostream>

class Animal
{
	public:

		Animal();
		Animal(const Animal &Other);
		Animal &operator=(const Animal &Other);
		virtual ~Animal();

		std::string getType() const;
		void setType(const std::string type);

		void virtual makeSound() const = 0;

	protected:

		std::string	_type;
};

#endif
