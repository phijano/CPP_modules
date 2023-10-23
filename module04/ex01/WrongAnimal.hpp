/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:31:25 by phijano-          #+#    #+#             */
/*   Updated: 2023/06/21 11:39:42 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL
 #define WRONGANIMAL

#include <iostream>

class WrongAnimal
{
	public:

		WrongAnimal();
		WrongAnimal(const WrongAnimal &Other);
		WrongAnimal &operator=(const WrongAnimal &Other);
		~WrongAnimal();

		std::string getType() const;
		void setType(const std::string type);

		void makeSound() const ;

	protected:

		std::string	_type;
};

#endif
