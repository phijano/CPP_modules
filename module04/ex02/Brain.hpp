/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:01:44 by phijano-          #+#    #+#             */
/*   Updated: 2023/06/21 11:13:48 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN
 #define BRAIN

#include <iostream>

class Brain
{
	public:

		Brain();
		Brain(const Brain &Other);
		Brain &operator=(const Brain &Other);
		~Brain();

	private:

		std::string _ideas[100];
};

#endif
