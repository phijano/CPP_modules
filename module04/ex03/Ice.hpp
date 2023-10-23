/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:21:37 by phijano-          #+#    #+#             */
/*   Updated: 2023/06/26 10:22:17 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

#include <iostream>
#include "AMateria.hpp"

class Ice: public AMateria
{

	public:

		Ice(std::string const &type);
		Ice();
		Ice(const Ice &Other);
		Ice &operator=(const Ice &Other);
		~Ice();

		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif
