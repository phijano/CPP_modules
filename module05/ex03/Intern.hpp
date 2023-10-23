/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:39:05 by phijano-          #+#    #+#             */
/*   Updated: 2023/07/17 10:18:35 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{

	public:

		Intern();
		Intern(const Intern &Other);
		Intern &operator=(const Intern &Other);
		virtual ~Intern();

		AForm *makeForm(const std::string &name, const std::string &target);
};

#endif
