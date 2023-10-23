/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:50:36 by phijano-          #+#    #+#             */
/*   Updated: 2023/08/22 11:19:32 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
 #define EASYFIND_HPP

class NoFoundException: public std::exception
{
	public:
		const char * what () const throw ()
		{
			return "Not found any coincidences";
		}
};

template <typename T>
typename T::iterator easyfind(T &container, const int &item)
{
	typename T::iterator result;
   	
	result = std::find(container.begin(), container.end(), item);  
	if (result == container.end())
		throw NoFoundException();
	return result;
}

#endif
