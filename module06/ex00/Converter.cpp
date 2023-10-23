/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:51:52 by phijano-          #+#    #+#             */
/*   Updated: 2023/08/04 10:56:40 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter(const std::string &value)
{
	//std::cout << "Converter constructor called" << std::endl;
	convert(value);
}

Converter::Converter()
{
	//std::cout << "Converter default constructor called" << std::endl;
	_valueChar = 0;
	_valueInt = 0;
	_valueFloat = 0;
	_valueDouble = 0;
	for (int i = 0; i < 4; i++)
		_possible[i] = true;
}

Converter::Converter(const Converter& other)
{
	//std::cout << "Converter copy constructor called" << std::endl;
	*this = other;
}

Converter& Converter::operator=(const Converter& other)
{
	//std::cout << "Converter assignation operator called" << std::endl;
	_valueChar = other._valueChar;
	_valueInt = other._valueInt;
	_valueFloat = other._valueFloat;
	_valueDouble = other._valueDouble;
	for (int i = 0; i < 4; i++)
		_possible[i] = other._possible[i];
	return *this;
}

Converter::~Converter()
{
	//std::cout << "Converter destructor called" << std::endl;
}

const char &Converter::getChar() const
{
	return _valueChar;
}

const int &Converter::getInt() const
{
	return _valueInt;
}
const float &Converter::getFloat() const
{
	return _valueFloat;
}
const double &Converter::getDouble() const
{
	return _valueDouble;
}

const bool &Converter::hasChar() const
{
	return _possible[CHAR];
}

const bool &Converter::hasInt() const
{
	return _possible[INT];
}

const bool &Converter::hasFloat() const
{
	return _possible[FLOAT];
}

const bool &Converter::hasDouble() const
{
	return _possible[DOUBLE];
}

void Converter::checkPseudo(std::string value)
{
	std::string literal[8] = {"inf", "+inf",  "inff", "+inff", "-inf", "-inff", "nan", "nanf"};
	for (unsigned int i = 0 ; i < value.size(); i++)
		value[i] = tolower(value[i]);
	for (int i = 0; i < 8; i++)
		if (value == literal[i])
		{
			_possible[CHAR] = false;
			_possible[INT] = false;
			if (i < 4)
			{
				_valueFloat = std::numeric_limits<float>::infinity();
				_valueDouble = std::numeric_limits<double>::infinity();
			}
			else if (i < 6)
			{
				_valueFloat = -std::numeric_limits<float>::infinity();
				_valueDouble = -std::numeric_limits<double>::infinity();
			}
			else
			{
				_valueFloat = std::numeric_limits<float>::quiet_NaN();
				_valueDouble = std::numeric_limits<double>::quiet_NaN();
			}
			break;
		}
}

static void detectType(const std::string &value, convType &strType, bool &sign)
{
	unsigned int i = 0;
	bool digit = false;

	if (value.size() == 1 && isprint(value[0]) && !isdigit(value[0]))
		strType = CHAR;
	else if (value.size() > 0)
	{
		while (value[i] && isspace(value[i]))
			i++;
		if (value[i] == '+' || value[i] == '-')
			if (value[i++] == '-')
				sign = true;
		while (value[i] && isdigit(value[i]))
			i++;
		if (i > 0 && isdigit(value[i - 1]))
			digit = true;
		if (i == value.size() && digit)
			strType = INT;
		else if (value[i] == '.')
		{
			i++;
			while (value[i] && isdigit(value[i]))
				i++;
			if (isdigit(value[i - 1]))
				digit = true;
			if (i == value.size() && digit)
				strType = DOUBLE;
		}
		if (value[i] == 'f' && !value[i + 1] && digit)
			strType = FLOAT;
	}
}

static bool checkOverflow(std::string value, bool &sign)
{
	int i = 0;
	int number = 0;
	int add;
	int exp = 1;

	i = value.size() - 1;
	while (i >= 0 && value[i] && isdigit(value[i]))
	{
		add = (value[i] - 48) * exp;
		if (sign)
		{
			if (-number < std::numeric_limits<int>::min() + add)
				return true;
		}
		else if (number > std::numeric_limits<int>::max() - add)
		{
			std::cout << number << std::endl;
			return true;
		}
		number = number + add;
		exp = exp * 10;
		i--;
	}
	return false;
}

void Converter::charToOthers()
{
	_valueInt = static_cast<int>(_valueChar);
	_valueFloat = static_cast<float>(_valueChar);
	_valueDouble = static_cast<double>(_valueChar);

}

void Converter::intToOthers()
{
	if (_valueInt >= 0 && _valueInt <= std::numeric_limits<char>::max())
		_valueChar = static_cast<char>(_valueInt);
	else
		_possible[CHAR] = false;
	_valueFloat = static_cast<float>(_valueInt);
	_valueDouble = static_cast<double>(_valueInt);

}

void Converter::floatToOthers()
{
	if (_valueFloat >= 0 && _valueFloat <= std::numeric_limits<char>::max())
		_valueChar = static_cast<char>(_valueFloat);
	else
		_possible[CHAR] = false;
	if (_valueFloat >= std::numeric_limits<int>::min() && _valueFloat <= std::numeric_limits<int>::max())
	{
		_valueInt = static_cast<int>(_valueFloat);
		if ((_valueInt > 0  && _valueFloat < 0) || (_valueInt < 0 && _valueFloat > 0))
			_possible[INT] = false;
	}
	else 
		_possible[INT] = false;
	_valueDouble = static_cast<double>(_valueFloat);

}
void Converter::doubleToOthers()
{
	if (_valueDouble >= 0 && _valueDouble <= std::numeric_limits<char>::max())
		_valueChar = static_cast<char>(_valueDouble);
	else
		_possible[CHAR] = false;
	if (_valueDouble >= std::numeric_limits<int>::min() && _valueDouble <= std::numeric_limits<int>::max())
	{
		_valueInt = static_cast<int>(_valueDouble);
	}
	else
		_possible[INT] = false;
	_valueFloat = static_cast<float>(_valueDouble);
}

void Converter::getValues(const std::string &value, convType &strType, bool sign)
{
	switch(strType)
	{
		case CHAR:
			_valueChar = value[0];
			charToOthers();
			break;
		case INT:
			if (!checkOverflow(value, sign))
			{
				_valueInt = atoi(value.c_str());
				intToOthers();
			}
			else
				for (int i = 0; i < 4; i++)
					_possible[i] = false;
			break;
		case FLOAT:
			_valueFloat = atof(value.c_str());
			floatToOthers();
			break;
		case DOUBLE:
			_valueDouble = atof(value.c_str());
			doubleToOthers();
			break;
		default:
			for (int i = 0; i < 4; i++)
				_possible[i] = false;
			break;
	}
}

void Converter::convert(const std::string &value)
{
	convType strType = JUNK;
	bool sign = false;

	for (int i = 0; i < 4; i++)
		_possible[i] = true;
	
	checkPseudo(value);
	if (_possible[CHAR])
	{
		detectType(value, strType, sign);
		getValues(value, strType, sign);
	}
}

std::ostream &operator<<(std::ostream &os, const Converter &conv)
{
	os << "char: ";
	if (!conv.hasChar())
		os << "impossible" << std::endl;
	else if (conv.getChar() < 32 || conv.getChar() > 126)
		os << "Non displayable" << std::endl;
	else
		os << "'" << conv.getChar() << "'" << std::endl;

	os << "int: "; 
	if (!conv.hasInt())
		os << "impossible" << std::endl;
	else
		os << conv.getInt() <<  std::endl;

	os << "float: ";
	if (!conv.hasFloat())
		os << "impossible" << std::endl;
	else
	{
		os << conv.getFloat();
		if (std::floor(conv.getFloat()) == conv.getFloat() && conv.getFloat() < 1000000 && conv.getFloat() > -1000000)
			os << ".0";
		os << "f" << std::endl;
	}
	os << "double: ";
	if (!conv.hasDouble())
		os << "impossible" << std::endl;
	else
	{
		os << conv.getDouble();
		if (std::floor(conv.getDouble()) == conv.getDouble() && conv.getDouble() < 1000000 && conv.getDouble() > -1000000)
			os << ".0";
		os << std::endl;
	}

	return os;
}
