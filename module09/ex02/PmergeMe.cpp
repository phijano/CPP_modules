/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:10:46 by phijano-          #+#    #+#             */
/*   Updated: 2023/09/15 10:53:08 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): _unsortedNumbers(NULL)
{
}

PmergeMe::PmergeMe(char **numbers): _unsortedNumbers(numbers)
{

}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	_unsortedNumbers = other._unsortedNumbers;
	return *this;
}

PmergeMe::~PmergeMe()
{
}
int PmergeMe::checkNumbers()
{
	std::string numberStr;
	unsigned int number;
	unsigned int pot;


	for (int i = 0; _unsortedNumbers[i]; i++)
	{
		numberStr = _unsortedNumbers[i];
		if (!std::all_of(numberStr.begin(), numberStr.end(), isdigit))
		{
			std::cout << "Error invalid argument: " << numberStr << std::endl;
			return 1;
		}
		else if (numberStr.size() > 10)
		{
			std::cout << "Error overflow: " << numberStr << std::endl;
			return 1;
		}
		else if (numberStr.size() == 10)
		{
			number = 0;
			pot = 1;
			for (std::string::iterator it = numberStr.end() - 1; it > numberStr.begin(); it--)
			{
				number += (*it - '0') * pot;
				pot *= 10;
			}
			if (*numberStr.begin() - '0' > 2 || (*numberStr.begin() == '2' && 2000000000 > std::numeric_limits<int>::max() - number))
			{	
				std::cout << "Error overflow: " << numberStr << std::endl;
				return 1;
			}
		}
		_myV.push_back(atoi(_unsortedNumbers[i]));
		_myD.push_back(atoi(_unsortedNumbers[i]));
	}
	return 0;
}

unsigned int PmergeMe::getJacGroup(unsigned int index)
{
	static const unsigned int	jacobsthal_diff[] = {
        2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
        2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
        1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
        178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u};
	
	return jacobsthal_diff[index];
}


void PmergeMe::vectorInsert(int item, int pair , std::vector<int>::iterator last, int oddSeq)
{
	unsigned int				jacGroup;
	unsigned int				firstPend;
	bool						is_pend;
	std::vector<int>			chain;
	std::vector<int>			pend;

	chain.insert(chain.begin(), _myV.begin(), _myV.begin() + item);
	for (std::vector<int>::iterator it = _myV.begin() + item; it < last; it += pair)
		chain.insert(chain.end(), it, it + item);

	for (std::vector<int>::iterator it = _myV.begin() + pair; it < last; it += pair)
		pend.insert(pend.end(), it, it + item);

	is_pend = true;
	firstPend = 0;
	jacGroup = 0;
	while(is_pend)
	{
		unsigned int groupSize = getJacGroup(jacGroup);

		if (pend.size() <= firstPend + groupSize * item)
		{
			groupSize = (pend.size() - firstPend) / item;
			is_pend = false;		static std::vector<int>	_myV;
		static std::deque<int>		_myD;
		}

		for (unsigned int i = groupSize; i > 0; i--)
		{
			unsigned pendIndex = firstPend - 1 + i * item;
			for (unsigned int i = item - 1; i < chain.size(); i += item)
			{
				if (pend[pendIndex] <= chain[i])
				{
					chain.insert(chain.begin() + i - item + 1, pend.begin() + pendIndex - item + 1, pend.begin() + pendIndex + 1);
					break;
				}
			}
		}

		firstPend += groupSize * item;
		jacGroup++;
	}
	if (oddSeq)
	{
		if (oddSeq >= item)
		{
			for (std::vector<int>::iterator i = chain.begin() + item - 1; i < chain.end(); i += item)
			{
				if (*(last + item -1) <= *i)
				{
					chain.insert(i - item + 1, last, last + item);
					break;
				}
				if (i == chain.end() - 1)
				{
					chain.insert(chain.end(), last, last + item);
					break;
				}
			}
			oddSeq -= item;
		}
		for (int i = oddSeq; i > 0; i--)
		{
			chain.push_back(*(_myV.end() - i));
		}
	}
	_myV = chain;

}

void PmergeMe::vectorSort(int item)
{
	int							pair;
	int							oddSeq;
	std::vector<int>::iterator	last;

	if (_myV.size() / item < 2)
		return;

	pair = item * 2;
	oddSeq = _myV.size() % pair;
	last = _myV.end() - oddSeq;

	for (std::vector<int>::iterator it = _myV.begin() + pair - 1; it < last; it += pair)
	{
		if (*it < *(it - item))
			std::swap_ranges(it - item + 1, it + 1, it - pair + 1);
	}

	vectorSort(pair);
	vectorInsert(item, pair, last, oddSeq);

}

void PmergeMe::dequeInsert(int item, int pair , std::deque<int>::iterator last, int oddSeq)
{
	unsigned int			jacGroup;
	unsigned int			firstPend;
	bool					is_pend;
	std::deque<int>			chain;
	std::deque<int>			pend;

	chain.insert(chain.begin(), _myD.begin(), _myD.begin() + item);
	for (std::deque<int>::iterator it = _myD.begin() + item; it < last; it += pair)
		chain.insert(chain.end(), it, it + item);

	for (std::deque<int>::iterator it = _myD.begin() + pair; it < last; it += pair)
		pend.insert(pend.end(), it, it + item);

	is_pend = true;
	firstPend = 0;
	jacGroup = 0;
	while(is_pend)
	{
		unsigned int groupSize = getJacGroup(jacGroup);

		if (pend.size() <= firstPend + groupSize * item)
		{
			groupSize = (pend.size() - firstPend) / item;
			is_pend = false;
		}

		for (unsigned int i = groupSize; i > 0; i--)
		{
			unsigned pendIndex = firstPend - 1 + i * item;
			for (unsigned int i = item - 1; i < chain.size(); i += item)
			{
				if (pend[pendIndex] <= chain[i])
				{
					chain.insert(chain.begin() + i - item + 1, pend.begin() + pendIndex - item + 1, pend.begin() + pendIndex + 1);
					break;
				}
			}
		}

		firstPend += groupSize * item;
		jacGroup++;
	}
	if (oddSeq)
	{
		if (oddSeq >= item)
		{
			for (std::deque<int>::iterator i = chain.begin() + item - 1; i < chain.end(); i += item)
			{
				if (*(last + item -1) <= *i)
				{
					chain.insert(i - item + 1, last, last + item);
					break;
				}
				if (i == chain.end() - 1)
				{
					chain.insert(chain.end(), last, last + item);
					break;
				}
			}
			oddSeq -= item;
		}
		for (int i = oddSeq; i > 0; i--)
		{
			chain.push_back(*(_myD.end() - i));
		}
	}
	_myD = chain;
}

void PmergeMe::dequeSort(int item)
{
	int							pair;
	int							oddSeq;
	std::deque<int>::iterator	last;

	if (_myD.size() / item < 2)
		return;

	pair = item * 2;
	oddSeq = _myD.size() % pair;
	last = _myD.end() - oddSeq;

	for (std::deque<int>::iterator it = _myD.begin() + pair - 1; it < last; it += pair)
	{
		if (*it < *(it - item))
			std::swap_ranges(it - item + 1, it + 1, it - pair + 1);
	}

	dequeSort(pair);
	dequeInsert(item, pair, last, oddSeq);

}

void PmergeMe::sort(char **numbers)
{
	_unsortedNumbers = numbers;
	sort();
}

void PmergeMe::sort()
{
	clock_t argsTime;
	clock_t vectorTime;
	clock_t dequeTime;

	if (!_unsortedNumbers)
	{
		std::cout << "Error: There aren't numbers to sort";
		return;
	}

	argsTime = clock();
	if (checkNumbers())
		return;
	argsTime = clock() - argsTime;
	vectorSort(1);
	vectorTime = clock() - argsTime;
	dequeSort(1);
	dequeTime = clock() - vectorTime;

	std::cout << "Before: ";
	for (int i = 0; _unsortedNumbers[i]; i++)
		std::cout << _unsortedNumbers[i] << " ";
	std::cout << std::endl;

	std::cout << "After:  ";
	for (std::vector<int>::iterator it = _myV.begin(); it < _myV.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _myV.size() << " elements with std:vector : " << (float)(vectorTime + argsTime) * 1000000 / CLOCKS_PER_SEC << " us" << std::endl;
	std::cout << "Time to process a range of " << _myD.size()  << " elements with std:deque  : "<< (float)(dequeTime + argsTime) * 1000000 /CLOCKS_PER_SEC << " us" << std::endl;
}
