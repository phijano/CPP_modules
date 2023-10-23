/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:32:13 by phijano-          #+#    #+#             */
/*   Updated: 2023/07/14 12:38:26 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{

	public:

		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &Other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &Other);
		~ShrubberyCreationForm();
		void execute(const Bureaucrat &executor) const;

	private:

		std::string _target;
};

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &bureaucrat);

#endif
