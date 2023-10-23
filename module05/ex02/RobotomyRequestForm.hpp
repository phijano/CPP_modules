/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:21:02 by phijano-          #+#    #+#             */
/*   Updated: 2023/07/13 12:15:46 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{

	public:

		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &Other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &Other);
		~RobotomyRequestForm();
		void execute(const Bureaucrat &executor) const;

	private:

		std::string _target;

};

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &bureaucrat);

#endif
