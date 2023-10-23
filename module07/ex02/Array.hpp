/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:31:41 by phijano-          #+#    #+#             */
/*   Updated: 2023/08/10 13:48:41 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
 #define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
	public:

		Array():_size(0)
		{
			_array = new T[0];
		}

		Array(unsigned int size): _size(size)
		{
			_array = new T[size];
		}

		Array(Array &other): _size(other._size)
		{
			_array = new T[_size];
			for (unsigned int i = 0 ;i < _size;i++)
				_array[i] = other._array[i];
		}
		Array &operator=(Array &other)
		{
			delete[] _array;
			_size = other._size;
			_array = new T[_size];
			for (unsigned int i = 0; i < _size ; i++)
				_array[i] = other._array[i];
			return *this;
		}
		
		~Array()
		{
			delete[] _array;
		}


		T &operator[](unsigned int index)
		{
			if (index >= _size) 
				throw OutOfSizeException();
			return _array[index];
		}

		unsigned int size()
		{
			return _size;
		}

	private:

		T*				_array;
		unsigned int	_size;
		class OutOfSizeException: public std::exception
		{	
			const char * what () const throw ()
			{
				return "Index out of range";
			}
		};
};

#endif
