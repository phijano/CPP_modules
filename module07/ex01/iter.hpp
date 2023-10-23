/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:59:18 by phijano-          #+#    #+#             */
/*   Updated: 2023/08/11 11:55:06 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
 #define ITER_HPP

template<typename T>
void iter(T *array, unsigned int size, void(*function)(const T &))
{
	for (unsigned int i = 0; i < size; i++)
		function(array[i]);
}

template<typename T>
void show(T &thing)
{
	std::cout << thing << std::endl;
}

#endif
