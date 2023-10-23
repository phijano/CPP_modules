/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:37:36 by phijano-          #+#    #+#             */
/*   Updated: 2023/08/22 11:41:33 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
 #define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		
		MutantStack();
		MutantStack(MutantStack &other);
		MutantStack &operator=(MutantStack &other);
		~MutantStack();
		
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin();
		iterator end();
};

#include "MutantStack.tpp"

#endif
