/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:22:26 by phijano-          #+#    #+#             */
/*   Updated: 2023/03/01 12:23:50 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT
#define CONTACT

#include <iostream>

class Contact
{
	public:

		Contact();
		Contact(const Contact &Other);
		Contact &operator=(const Contact &Other);
		~Contact();

		void		setFirst(std::string First);
		void		setLast(std::string Last);
		void		setNick(std::string Nick);
		void		setPhone(std::string Phone);
		void		setSecret(std::string Secret);
		std::string	getFirst();
		std::string	getLast();
		std::string	getNick();
		std::string	getPhone();
		std::string	getSecret();

	private:

		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
};

#endif
