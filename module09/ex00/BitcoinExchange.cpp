/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:13:33 by phijano-          #+#    #+#             */
/*   Updated: 2023/09/12 13:39:06 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string arg)
{
	if (!loadDatabase())
	exchangeFile(arg);
}

BitcoinExchange::BitcoinExchange()
{
	loadDatabase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	_mapData = other._mapData;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

int BitcoinExchange::loadDatabase()
{
	std::string		data;	
	std::ifstream	dataFile("data.csv");
	unsigned int	sep;

	if (dataFile.is_open())
	{
		getline(dataFile, data);
		while (getline(dataFile, data))
		{	
			sep = data.find(",", 0);
			_mapData[data.substr(0, sep)] = atof(data.substr(sep + 1, data.size()).c_str());
		}
		dataFile.close();
	}
	else
	{
		std::cout << "Error opening database" << std::endl;
		return 1;
	}
	return 0;
}


bool BitcoinExchange::checkDate(std::string input)
{
	int	year;
	int	month;
	int	day;

	if (input.size() == 10 && input[4] == '-' && input[7] == '-'
			&& std::all_of(input.begin(), input.begin() + 4, isdigit) 
				&& std::all_of(input.begin() + 5, input.begin() + 7, isdigit) 
					&& std::all_of(input.begin() + 8, input.begin() + 10, isdigit))
	{
		year = atoi(input.substr(0, 4).c_str());
		month = atoi(input.substr(5, 2).c_str());
		day = atoi(input.substr(8, 2).c_str());
		if (month < 1 || month > 12 || day < 1 || day > 31 || (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) || (day > 29 && month == 2) 
						|| (day > 28 && month == 2 && !((year % 4 == 0 && year % 100 != 100) || year % 400 == 0)))
					std::cout << "Error: bad date => " << input << std::endl;
		else if (year < 2009 || (year == 2009 && month == 1 && day < 2))
			std::cout << "Error: no exchange for bitcoin before 2009-01-02 => " << input << std::endl;
		else
			return true;
	}
	else
		std::cout << "Error: bad date => " << input << std::endl;
	return false;
}

bool BitcoinExchange::checkValue(std::string input)
{
	std::stringstream	myStream;

	myStream.clear();
	myStream.str(input);
	if (myStream >> _value)
		if (myStream.eof())
		{
			if (_value >= 0 && _value <= 1000)
				return true;
			else
			{
				if (_value < 0)
					std::cout << "Error: not a positive number." << std::endl;
				else
					std::cout << "Error: too large a number." << std::endl;
				return false;
			}
		}
	std::cout << "Error: bad value =>" << input << std::endl;
	return false;
}

void BitcoinExchange::exchange(std::string input)
{
	unsigned int	sepIndex;
	std::string		date;
	std::string		value;

	sepIndex = input.find("|", 0);
	if (sepIndex == 0 || sepIndex >= input.size() - 1)
		std::cout << "Error: bad input => " << input << std::endl;
	else
	{
		date = input.substr(0, sepIndex - 1);
		value = input.substr(sepIndex + 1, input.size());
		if (checkDate(date) && checkValue(value))
		{
			std::map<std::string, double >::iterator it = _mapData.upper_bound(date);
			it--;
			std::cout << date << " => "<< _value << " = " << it->second * _value << std::endl;
		}
	}
}

void BitcoinExchange::exchangeFile(std::string file)
{
	std::string		input;	
	std::ifstream	inputFile(file);

	if (_mapData.empty())
	{
		std::cout << "Error no database" << std::endl;;
		return;
	}
	if (inputFile.is_open())
	{
		getline(inputFile, input);
		if (input == "date | value")
			while (getline(inputFile, input))
				exchange(input);
		else
			std::cout << "Error in file: " << file << ", expected table: date | value" << std::endl;
		inputFile.close();
	}	
	else
		std::cout << "Error opening file: " << file << std::endl;
}
