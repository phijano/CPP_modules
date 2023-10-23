/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:36:55 by phijano-          #+#    #+#             */
/*   Updated: 2023/08/10 10:51:15 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
 #define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T a, T b)
{
	if (a < b)
		return a;
	return b;
}

template <typename T>
T max(T a, T b)
{
	if (a > b)
		return a;
	return b;
}

#endif
