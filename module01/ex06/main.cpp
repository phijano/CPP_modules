/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:13:03 by phijano-          #+#    #+#             */
/*   Updated: 2023/05/11 11:08:12 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int	main(int argc, char **args)
{
	std::string mapLevels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	Harl myHarl;
	int level;

	if (argc == 2)
	{
		for (level = 0; level < 4; level++)
			if (std::string(args[1]) == mapLevels[level])
				break;
		switch (level)
		{
			case 0:
				std::cout << "[ DEBUG ]" << std::endl;
				myHarl.complain("DEBUG");
				std::cout << std::endl;
			case 1:
				std::cout << "[ INFO ]" << std::endl;
				myHarl.complain("INFO");
				std::cout << std::endl;
			case 2:
				std::cout << "[ WARNING ]" << std::endl;
				myHarl.complain("WARNING");
				std::cout << std::endl;
			case 3:
				std::cout << "[ ERROR ]" << std::endl;
				myHarl.complain("ERROR");
				std::cout << std::endl;
				break;
			default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		}
	}
	else
	{
			std::cout << "use like this: ./Harlfilter \"level\" " << std::endl;
			std::cout << "available levels: \"DEBUG\", \"INFO\", \"WARNING\", \"ERROR\"" << std::endl;
	}
	return 0;
}
