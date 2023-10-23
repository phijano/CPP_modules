/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:41:54 by phijano-          #+#    #+#             */
/*   Updated: 2023/04/26 12:04:31 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string brain;
	std::string *stringPTR;
	std::string &stringREF = brain;

	stringPTR = &brain;
	brain = "HI THIS IS BRAIN";

	std::cout << "variable memory direction:  " << &brain << std::endl;
	std::cout << "reference memory direction: " << &stringREF << std::endl;
	std::cout << "pointer memory direction:   " << stringPTR << std::endl;

	std::cout << "variable value:  " << brain << std::endl;
	std::cout << "reference value: " << stringREF << std::endl;
	std::cout << "pointer value:   " << *stringPTR << std::endl;
	return 0;
}
