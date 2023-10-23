/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:40:03 by phijano-          #+#    #+#             */
/*   Updated: 2023/05/22 12:23:13 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP
#define FRAGTRAP

#include <iostream>
#include "ClapTrap.hpp"

class	FragTrap: virtual public ClapTrap
{
	public:

		FragTrap();
		FragTrap(const FragTrap &Other);
		FragTrap &operator=(const FragTrap &Other);
		~FragTrap();
		FragTrap(std::string name);
		void	highFivesGuys();
};

#endif
