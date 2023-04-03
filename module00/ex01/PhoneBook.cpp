/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:21:39 by phijano-          #+#    #+#             */
/*   Updated: 2023/03/02 11:27:38 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_newContactIndex = 0;
}

PhoneBook::PhoneBook(const PhoneBook &other)
{
	*this = other;
}

PhoneBook &PhoneBook::operator=(const PhoneBook &other)
{
	for (int i = 0; i < 8; i++)
		_myContacts[i] = other._myContacts[i];
	_newContactIndex = other._newContactIndex;
	return *this;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::start()
{
	std::string command;

	while(1)
	{
		std::cout << "Introduzca ADD para añadir contacto, SEARCH para buscar contactos o EXIT para salir: ";
		getline(std::cin, command);
		if (command == "ADD")
			add();
		else if (command == "SEARCH")
			search();
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Comando incorrecto." << std::endl;
	}
}

void PhoneBook::add()
{
	Contact	newContact;

	newContact.setFirst(getField("nombre"));
	newContact.setLast(getField("apellido"));
	newContact.setNick(getField("apodo"));
	newContact.setPhone(getPhone());
	newContact.setSecret(getField("secreto oscuro"));
	add(newContact);
}

std::string PhoneBook::getField(std::string nameField)
{
	std::string field;
	std::cout << "Introduca " << nameField << ": ";

	while(field == "")
	{
		getline(std::cin, field);
		if (field == "")
			std::cout << "No puede quedar vacío, introduzca " << nameField << ": ";
	}
	return field;
}

std::string PhoneBook::getPhone()
{
    std::string line;
	std::stringstream myStream;
    long phoneNumber;

	phoneNumber = 0;
	std::cout << "Introduca número de teléfono: ";
	while (phoneNumber == 0)
	{
    	while (std::getline(std::cin, line))
    	{
			myStream.clear();
			myStream.str(line);
			if (myStream >> phoneNumber)
				if (myStream.eof())
					break;
			std::cout << "Número de teléfono incorrecto, introduzca número de teléfono: ";
		}
		if (line.length() < 3 || line.length() > 16 || phoneNumber < 0)
		{
			std::cout << "Número de teléfono incorrecto, introduzca número de teléfono: ";
			phoneNumber = 0;
		}
	}
	return line;
}

void PhoneBook::add(Contact newContact)
{
	_myContacts[_newContactIndex] = newContact;
	if (_newContactIndex < 7)
		_newContactIndex++;
	else
		_newContactIndex = 0;
}

void PhoneBook::search()
{
	if (_myContacts[0].getFirst() == "")
		std::cout << "No hay contactos." << std::endl;
	else
	{
		std::cout << "    ÍNDICE|    NOMBRE|  APELLIDO|     APODO" << std::endl;
		std::cout.width(43);
		std::cout.fill('-');
		std::cout << "-" << std::endl;
		for (int i = 0; i < 8; i++)
			if (_myContacts[i].getFirst() != "")
				showContact(i);
		showFullContact(getIndex());
	}
}

int PhoneBook::getIndex()
{
    std::string line;
	std::stringstream myStream;
    int index;

	index = 0;
	std::cout << "Introduca el índice del contacto: ";
	while (index == 0)
	{
    	while (std::getline(std::cin, line))
    	{
			myStream.clear();
			myStream.str(line);
			if (myStream >> index)
				if (myStream.eof())
					break;
			std::cout << "Índice incorrecto, introduzca índice: ";
		}
		if (index < 1 || index > 8 || _myContacts[index - 1].getFirst()== "")
		{
			std::cout << "Indice incorrecto, introduzca indice: ";
			index = 0;
		}		
	}
	return (index - 1);
}

void PhoneBook::showContact(int index)
{
	std::stringstream field;

	field << index + 1;
	format(field.str());
	std::cout << '|';
	format(_myContacts[index].getFirst());
	std::cout << '|';
	format(_myContacts[index].getLast());
	std::cout << '|';
	format(_myContacts[index].getNick());
	std::cout << std::endl;
}

void PhoneBook::format(std::string field)
{
	std::cout.width(10);
	if (field.length() > 9)
	{
		std::cout.fill('.');
		std::cout << std::left << field.substr(0, 9);
	}
	else
	{
		std::cout.fill(' ');
		std::cout << std::right << field;
	}
}

void PhoneBook::showFullContact(int index)
{
	std::cout << "Nombre: " << _myContacts[index].getFirst() << std::endl;
	std::cout << "Apellido: " << _myContacts[index].getLast() << std::endl;
	std::cout << "Apodo: " << _myContacts[index].getNick() << std::endl;
	std::cout << "Número de teléfono: " << _myContacts[index].getPhone() << std::endl;
	std::cout << "Secreto oscuro: " << _myContacts[index].getSecret() << std::endl;
}


