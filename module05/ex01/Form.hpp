/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:30:04 by phijano-          #+#    #+#             */
/*   Updated: 2023/07/13 12:18:02 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	public:

		Form(const std::string &name, const short &gradeToSign, const short &gradeToExecute);
		Form();
		Form(const Form &Other);
		Form &operator=(const Form &Other);
		~Form();

		std::string const &getName() const;
		const bool &getSigned() const;
		const short &getGradeToSign() const;
		const short &getGradeToExecute() const;
		void beSigned(const Bureaucrat &bureaucrat);

	private:

		const std::string _name;
		bool _signed;
		const short _gradeToSign;
		const short _gradeToExecute;
		class GradeTooHighException;
		class GradeTooLowException;
};

std::ostream &operator<<(std::ostream &os, const Form &bureaucrat);

#endif
