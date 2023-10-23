/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:25:19 by phijano-          #+#    #+#             */
/*   Updated: 2023/07/13 12:08:22 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	public:

		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &Other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &Other);
		~PresidentialPardonForm();
		void execute(const Bureaucrat &executor) const;

	private:

		std::string _target;

};

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &bureaucrat);

#endif
