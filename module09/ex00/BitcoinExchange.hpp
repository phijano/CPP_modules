/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:47:56 by phijano-          #+#    #+#             */
/*   Updated: 2023/09/12 12:29:10 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
 #define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange
{
	public:

		BitcoinExchange(std::string file);
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();
		int		loadDatabase();
		void	exchangeFile(std::string file);

	private:

		std::map<std::string, double>	_mapData;
		double							_value;
		bool	checkDate(std::string input);
		bool	checkValue(std::string input);
		void	exchange(std::string file);
};

#endif
