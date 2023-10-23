/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 09:47:37 by phijano-          #+#    #+#             */
/*   Updated: 2023/06/26 10:01:23 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_H
# define MATERIA_H

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		
		std::string _type;

	public:

		AMateria(std::string const &type);
		AMateria();
		AMateria(const AMateria &Other);
		AMateria &operator=(const AMateria &Other);
		virtual ~AMateria();


		std::string const &getType() const;
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);
};

#endif
