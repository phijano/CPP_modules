/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:08:12 by phijano-          #+#    #+#             */
/*   Updated: 2023/04/26 12:48:18 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON
#define WEAPON

#include <iostream>

class	Weapon
{
	public:
		Weapon();
		Weapon(std::string type);
		void		setType(std::string type);
		std::string	getType();

	private:

		std::string	_type;

};

#endif
