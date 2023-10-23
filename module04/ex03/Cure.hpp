/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:58:51 by phijano-          #+#    #+#             */
/*   Updated: 2023/06/26 09:50:53 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H

#include <iostream>
#include "AMateria.hpp"

class Cure: public AMateria
{

	public:
		
		Cure(std::string const &type);
		Cure();
		Cure(const Cure &Other);
		Cure &operator=(const Cure &Other);
		~Cure();

		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif
