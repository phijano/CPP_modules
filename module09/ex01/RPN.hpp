/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:41:10 by phijano-          #+#    #+#             */
/*   Updated: 2023/09/12 13:31:07 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
 #define RPN_HPP

#include <iostream>
#include <stack>

enum	RPNType {NUMBER, OPERATION, JUNK};
enum	OperatorType {PLUS, MINUS, MULT, DIV};

class RPN
{
	public:

		RPN(std::string arg);
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();
		void solve(std::string arg);

	private:

		bool	_error;

		int		getOperand(std::stack<int> &operands);
		bool	getNext(std::string &arg, std::string &dat);
		RPNType	check(std::string dat);
		int		operation(std::stack<int> &operands, std::string operate);
		
		class	ZeroDivisionException;
};

#endif
