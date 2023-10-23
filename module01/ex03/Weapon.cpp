/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:08:29 by phijano-          #+#    #+#             */
/*   Updated: 2023/04/26 12:54:19 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string type)
{
	_type = type;
}

void	Weapon::setType(std::string type)
{
	_type = type;
}

std::string	Weapon::getType(void)
{
	return _type;
}
