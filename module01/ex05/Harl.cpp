/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:44:20 by phijano-          #+#    #+#             */
/*   Updated: 2023/05/11 10:51:03 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::complain(std::string level)
{
	void (Harl::*messagePtr[])(void)= {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string availableLevel[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for	(int i = 0; i < 4; i++)
	{
		if (level == availableLevel[i])
		{
			(this->*messagePtr[i])();
			break ;
		}
	}
}

void	Harl::debug(void)
{
	std::cout << "Debug: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "Info: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "Warning: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "Error: This is unacceptable! I want to speak to the manager now." << std::endl;
}

