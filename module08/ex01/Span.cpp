/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:31:51 by phijano-          #+#    #+#             */
/*   Updated: 2023/08/22 11:07:25 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(const unsigned int &size): _size(size), _numberOfItems(0)
{
}

Span::Span(): _size(0), _numberOfItems(0)
{
}

Span::Span(const Span& other)
{
	*this = other;
}

Span& Span::operator=(const Span& other)
{
	_size = other._size;
	_numberOfItems = other._numberOfItems;
	_span = other._span;
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(const int &number)
{
	if (_numberOfItems == _size)
		throw FilledException();
	_numberOfItems++;
	_span.push_back(number);
}

unsigned int Span::shortestSpan() const
{
	if (_numberOfItems < 2)
		throw NoSpanException();

	std::vector<int> sortedSpan = _span;

	std::sort(sortedSpan.begin(), sortedSpan.end());
	std::vector<int> nextElementDiff = sortedSpan;
	sortedSpan.erase(--sortedSpan.end());
	nextElementDiff.erase(nextElementDiff.begin());
	transform(nextElementDiff.begin(), nextElementDiff.end(), sortedSpan.begin(), nextElementDiff.begin(), std::minus<int>());
	return *min_element(nextElementDiff.begin(), nextElementDiff.end());
}

int Span::longestSpan() const
{

	if (_numberOfItems < 2)
		throw NoSpanException();

	return *max_element(_span.begin(), _span.end()) - *min_element(_span.begin(), _span.end());
}
