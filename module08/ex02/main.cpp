/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:29:18 by phijano-          #+#    #+#             */
/*   Updated: 2023/08/22 12:05:00 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include <list>

int main(void)
{
	std::cout << "******Example test" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	
	std::cout << "******Example test (list)" << std::endl;
	std::list<int> mstackl;

	mstackl.push_back(5);
	mstackl.push_back(17);
	std::cout << mstackl.back() << std::endl;
	mstackl.pop_back();
	std::cout << mstackl.size() << std::endl;
	mstackl.push_back(3);
	mstackl.push_back(5);
	mstackl.push_back(737);
	//[...]
	mstackl.push_back(0);
	std::list<int>::iterator itl = mstackl.begin();
	std::list<int>::iterator itel = mstackl.end();
	++itl;
	--itl;
	while (itl != itel)
	{
		std::cout << *itl << std::endl;
		++itl;
	}
	std::list<int> sl(mstackl);



	std::cout << "******Copy test" << std::endl;

	MutantStack<int> *myStack = new MutantStack<int>;
	myStack->push(-22);	

	MutantStack<int> copyStack(*myStack);

	MutantStack<int>::iterator iter = myStack->begin();

	std::cout << "original" << std::endl;

	while (iter != myStack->end())
	{
		std::cout << *iter << std::endl;
		iter++;
	}

	std::cout << "copy" << std::endl;

	iter = copyStack.begin();
	while (iter != copyStack.end())
	{
		std::cout << *iter << std::endl;
		iter++;
	}

	copyStack.push(45);	
	copyStack.push(4);	
	copyStack.push(45);	
	copyStack.push(3);	
	copyStack.push(-32);	
	copyStack.push(66);	

	std::cout << "original" << std::endl;

	iter = myStack->begin();
	while (iter != myStack->end())
	{
		std::cout << *iter << std::endl;
		iter++;
	}

	std::cout << "copy" << std::endl;

	iter = copyStack.begin();
	while (iter != copyStack.end())
	{
		std::cout << *iter << std::endl;
		iter++;
	}

	delete myStack;
	return 0;
}
