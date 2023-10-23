/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:43:51 by phijano-          #+#    #+#             */
/*   Updated: 2023/09/11 13:46:44 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int argc, char **args)
{
	PmergeMe thing;
	if (argc > 1)
		thing.sort(&args[1]);
	return 0;
}
