/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:41:58 by phijano-          #+#    #+#             */
/*   Updated: 2023/05/26 10:49:23 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT
 #define WRONGCAT

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:

		WrongCat();
		WrongCat(const WrongCat &Other);
		WrongCat &operator=(const WrongCat &Other);
		~WrongCat();

		void makeSound() const;
};

#endif
