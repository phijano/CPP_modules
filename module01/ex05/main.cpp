/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:43:28 by phijano-          #+#    #+#             */
/*   Updated: 2023/05/03 12:06:12 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl myHarl;

	myHarl.complain("ERROR");
	myHarl.complain("INFO");
	myHarl.complain("DEBUG");
	myHarl.complain("WARNING");
	myHarl.complain("sdfsdfs");
	return 0;
}
