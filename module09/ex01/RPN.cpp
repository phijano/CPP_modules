/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:54:41 by phijano-          #+#    #+#             */
/*   Updated: 2023/09/15 12:17:37 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

class RPN::ZeroDivisionException: public std::exception
{
	const char * what () const throw ()
	{
		return "Error division by 0";
	}
};


RPN::RPN(std::string arg)
{
	solve(arg);
}

RPN::RPN()
{
}

RPN::RPN(const RPN& other)
{
	*this = other;
}

RPN& RPN::operator=(const RPN& other)
{
	(void) other;
	return *this;
}

RPN::~RPN()
{
}

bool RPN::getNext(std::string &arg, std::string &dat)
{
	unsigned int pos;

	if (arg.size() == 0)
		return false;	
	pos = arg.find(" ", 0);
	if (pos == 0)
	{
		arg.erase(arg.begin());
		return getNext(arg, dat);
	}
	else if (pos < arg.size())
	{
		dat = arg.substr(0, pos);
		arg = arg.substr(pos + 1, arg.size());
		check(dat);
	}
	else
	{
		dat = arg;
		arg = "";
	}
	return true;
}

RPNType RPN::check(std::string dat)
{
	std::string tokens = "+-*/";

	if (std::all_of(dat.begin(), dat.end(), isdigit))
		return NUMBER;
	else if (tokens.find(dat, 0) < tokens.size())
		return OPERATION;
	return JUNK;
}

int RPN::getOperand(std::stack<int> &operands)
{
	int number;

	if (operands.empty())
	{
		_error = true;
		return 1;
	}
	number = operands.top();
	operands.pop();
	return number;
}

int RPN::operation(std::stack<int> &operands, std::string operate)
{
	int result;
	int number;
	std::string tokens = "+-*/";

	number = getOperand(operands);
	result = getOperand(operands);
	switch(tokens.find(operate, 0))
	{
		case PLUS:
			result += number;
			break;
		case MINUS:
			result -= number;
			break;
		case MULT:
			result *= number;
			break;
		case DIV:
			if (number == 0)
				throw ZeroDivisionException();
			result /= number;
			break;
		default:
			break;
	}
	operands.push(result);
	return result;
}

void RPN::solve(std::string arg)
{
	std::string dat;
	std::stack<int> operands;

	_error = false;
	while(getNext(arg, dat) && !_error)
	{
		switch(check(dat))
		{
		case NUMBER:
			operands.push(atoi(dat.c_str()));
			break;
		case OPERATION:
			operation(operands, dat);
			break;
		case JUNK:
			_error = true;
			break;
		default:
			break;
		}
	}
	if (_error)
		std::cout << "Error" << std::endl;
	else if (operands.size() > 1)
		std::cout << "Error, there are numbers not used in operations." << std::endl;
	else
		std::cout << getOperand(operands) << std::endl;
}
