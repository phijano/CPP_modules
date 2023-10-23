/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:57:14 by phijano-          #+#    #+#             */
/*   Updated: 2023/08/10 11:06:18 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int main(void)
{
	char charArray[7] = {'+', '-', '.' , 'A', '0', '<', '#'};
	std::string stringArray[3] = {"barco", "lancha", "submarino"};
	float floatArray[4] = {2.3, 4.2, 42.0 , 24224.3223};

	::iter(charArray, 7, show);
	::iter(stringArray, 3, show);
	::iter(floatArray, 4, show);

	return 0;
}
