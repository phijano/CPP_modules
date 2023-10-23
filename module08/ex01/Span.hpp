/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:31:39 by phijano-          #+#    #+#             */
/*   Updated: 2023/08/22 11:16:44 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span
{
	public:

		Span(const unsigned int &size);
		Span();
		Span(const Span &Other);
		Span &operator=(const Span &Other);
		~Span();

		void addNumber(const int &number);
		unsigned int shortestSpan() const;
		int longestSpan() const;
		template<typename T>
		void addNumber(T start, T end)
		{
			if (_numberOfItems + distance(start, end) > _size)
				throw FilledException();
			_numberOfItems += distance(start, end);
			_span.insert(_span.end(), start, end);
		}

	private:

		std::vector<int>	_span;
		unsigned int		_size;
		unsigned int 		_numberOfItems;

		class FilledException: public std::exception
		{
			const char * what () const throw ()
			{ 
				return "Already added max limit of numbers";
			}
		};

		class NoSpanException: public std::exception
		{
			const char * what () const throw ()
			{ 
				return "Not enough numbers to find span";
			}
		};
};

#endif
