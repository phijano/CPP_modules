/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:26:03 by phijano-          #+#    #+#             */
/*   Updated: 2023/07/14 12:52:06 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void leaks(void)
{
	system("leaks No,youneed...");
}

int main()
{
	Bureaucrat pepe("Pepe", 2);
	AForm *shrub = new ShrubberyCreationForm("there");
	AForm *rob = new RobotomyRequestForm("me");
	AForm *par = new PresidentialPardonForm("you");

	pepe.signForm(*shrub);
	pepe.executeForm(*shrub);
	pepe.signForm(*rob);
	pepe.executeForm(*rob);
	pepe.signForm(*par);
	pepe.executeForm(*par);

	delete(shrub);
	delete(rob);
	delete(par);

	atexit(leaks);
	return 0;

}
