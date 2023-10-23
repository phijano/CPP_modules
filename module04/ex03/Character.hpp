/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:39:55 by phijano-          #+#    #+#             */
/*   Updated: 2023/06/26 11:42:48 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter
{ 
	public:

		Character();
		Character(const Character &Other);
		Character &operator=(const Character &Other);
		~Character();
		Character(std::string const & name);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);

	private:

		std::string _name;
		AMateria *_inventory[4];
};

#endif
