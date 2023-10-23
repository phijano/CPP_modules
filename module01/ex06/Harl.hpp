/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:10:25 by phijano-          #+#    #+#             */
/*   Updated: 2023/05/03 12:11:31 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL
#define HARL

#include <iostream>

class	Harl
{
	public:
		Harl();
		~Harl();
		void	complain(std::string level);

	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

#endif
