/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:34:52 by phijano-          #+#    #+#             */
/*   Updated: 2023/06/29 12:39:30 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERASOURCE_H
# define MATERASOURCE_H

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	public:

		MateriaSource();
		MateriaSource(const MateriaSource &Other);
		MateriaSource &operator=(const MateriaSource &Other);
		~MateriaSource();

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);

	private:

		AMateria *_inventory[4];
};

#endif
