/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:53:25 by phijano-          #+#    #+#             */
/*   Updated: 2023/06/29 11:46:25 by phijano-         ###   ########.fr       */
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

		void virtual makeSound() const ;

	protected:

		std::string	_type;
};

#endif
