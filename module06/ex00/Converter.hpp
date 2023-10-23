/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:44:47 by phijano-          #+#    #+#             */
/*   Updated: 2023/08/02 10:38:52 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

#include <iostream>
#include <cmath>

enum convType {CHAR, INT, FLOAT, DOUBLE, JUNK};


class Converter
{
	public:

		Converter(const std::string &value);
		Converter();
		Converter(const Converter &Other);
		Converter &operator=(const Converter &Other);
		~Converter();
		const char		&getChar() const;
		const int 		&getInt() const;
		const float 	&getFloat() const;
		const double 	&getDouble() const;
		const bool		&hasChar() const;
		const bool		&hasInt() const;
		const bool		&hasFloat() const;
		const bool		&hasDouble() const;
		void 			convert(const std::string &value);

	private:

		char		_valueChar;
		int			_valueInt;
		float 		_valueFloat;
		double 		_valueDouble;

		bool		_possible[4];

		void checkPseudo(const std::string value);
		void getValues(const std::string &value, convType &strType, bool sign);
		void charToOthers();
		void intToOthers();
		void floatToOthers();
		void doubleToOthers();

};

std::ostream &operator<<(std::ostream &os, const Converter &conv);

#endif
