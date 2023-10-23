/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:26:03 by phijano-          #+#    #+#             */
/*   Updated: 2023/07/17 10:23:53 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

void leaks(void)
{
	system("leaks Atleast...");
}

int main()
{
	Intern thirtySixHoursDay;
	AForm *uselessForm;

	uselessForm = thirtySixHoursDay.makeForm("robotomy request", "Terminator");
	std::cout << uselessForm->getName() << std::endl;
	delete (uselessForm);

	uselessForm = thirtySixHoursDay.makeForm("RObotomy request", "Terminator");
	std::cout << uselessForm->getName() << std::endl;
	delete (uselessForm);

	uselessForm = thirtySixHoursDay.makeForm("holidays request", "Terminator");

	Bureaucrat pepe("Pepe", 2);
	AForm *shrub = thirtySixHoursDay.makeForm("Shrubbery creation", "there");
	AForm *rob = thirtySixHoursDay.makeForm("robotomy request", "me");
	AForm *par = thirtySixHoursDay.makeForm("PRESIDENTIAL PARDON", "Terminator");

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
