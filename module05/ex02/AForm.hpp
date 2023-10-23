/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:18:48 by phijano-          #+#    #+#             */
/*   Updated: 2023/07/13 12:14:04 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
	public:

		AForm(const std::string &name, const short &gradeToSign, const short &gradeToExecute);
		AForm();
		AForm(const AForm &Other);
		AForm &operator=(const AForm &Other);
		virtual ~AForm();

		std::string const &getName() const;
		const bool &getSigned() const;
		const short &getGradeToSign() const;
		const short &getGradeToExecute() const;
		void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(const Bureaucrat &executor) const = 0;

	private:

		const std::string _name;
		bool _signed;
		const short _gradeToSign;
		const short _gradeToExecute;
		class GradeTooHighException;
		class GradeTooLowException;
		class NotSignedException;
};

std::ostream &operator<<(std::ostream &os, const AForm &bureaucrat);

#endif
