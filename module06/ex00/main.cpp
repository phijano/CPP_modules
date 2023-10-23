/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:29:48 by phijano-          #+#    #+#             */
/*   Updated: 2023/07/26 10:24:44 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Converter.hpp"

int	main(int argc, char **args)
{
	if (argc == 2)
	{
		Converter myConv(args[1]);
		std::cout << myConv;
	}
	return 0;
}
