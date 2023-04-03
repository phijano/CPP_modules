/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:21:26 by phijano-          #+#    #+#             */
/*   Updated: 2023/03/02 11:00:19 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK
#define PHONEBOOK

#include <iostream>
#include <sstream>
#include "Contact.hpp"

class PhoneBook 
{
	public:

		PhoneBook();
		PhoneBook(const PhoneBook &Other);
		PhoneBook &operator=(const PhoneBook &Other);
		~PhoneBook();

		void	start();

	private:
	
		int		_newContactIndex;	
		Contact	_myContacts[8];

		void		add();
		void		add(Contact newContact);
		std::string getField(std::string field);
		std::string	getPhone();
		void		search();
		int			getIndex();
		void		showContact(int index);
		void		format(std::string field);
		void		showFullContact(int index);
};

#endif
