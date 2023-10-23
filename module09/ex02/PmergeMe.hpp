/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:46:07 by phijano-          #+#    #+#             */
/*   Updated: 2023/09/12 11:45:25 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
 #define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>

class PmergeMe
{
	public:

		PmergeMe();
		PmergeMe(char **numbers);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		void	sort(char **numbers);
		void	sort();

	private:
		
		std::vector<int>	_myV;
		std::deque<int>		_myD;
		char **				_unsortedNumbers;	

		int				checkNumbers();	
		void			vectorSort(int item);
		void			vectorInsert(int item, int pair, std::vector<int>::iterator last, int oddSeq);
		void			dequeSort(int item);
		void			dequeInsert(int item, int pair, std::deque<int>::iterator last, int oddSeq);
		unsigned int	getJacGroup(unsigned int index);

};

#endif
