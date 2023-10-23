/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:37:33 by phijano-          #+#    #+#             */
/*   Updated: 2023/09/12 12:47:51 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main (int argc, char **args)
{

	if (argc == 2)
	{
		try
		{
			RPN myRPN(args[1]);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
