/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:34:43 by phijano-          #+#    #+#             */
/*   Updated: 2023/07/13 11:45:23 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>

class Bureaucrat
{
	public:

		Bureaucrat(const std::string &name, const short &grade);
		Bureaucrat();
		Bureaucrat(const Bureaucrat &Other);
		Bureaucrat &operator=(const Bureaucrat &Other);
		~Bureaucrat();

		const std::string &getName() const;
		const short &getGrade() const;
		void riseGrade();
		void downGrade();

	private:

		const std::string _name;
		short _grade;
		class GradeTooHighException;
		class GradeTooLowException;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
