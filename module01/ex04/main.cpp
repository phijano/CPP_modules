/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:38:48 by phijano-          #+#    #+#             */
/*   Updated: 2023/05/02 12:37:51 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>


void	writeFile(std::string fileOut, std::string myOutputText)
{
	fileOut += ".replace";
	std::ofstream myWriteFile(fileOut);
	if (myWriteFile.is_open())
		myWriteFile << myOutputText;
	else
		std::cout << "Error opening " << fileOut << std::endl;
}

void	replace(char **args)
{
	std::string	myReadText;
	std::string myOutputText;
	int index;

	std::ifstream myReadFile(args[1]);
	if (myReadFile.is_open())
	{
		while (getline(myReadFile, myReadText))
		{
			index = 0;
			while(index > -1)
			{
				index = myReadText.find(args[2]);
				if (index > -1)
				{
					myOutputText += myReadText.substr(0, index) + args[3];
					myReadText.erase(0, index + strlen(args[2]));
				}
			}
			myOutputText += myReadText + "\n";			
		}
		writeFile(std::string(args[1]), myOutputText);
	}
	else
		std::cout << "Error opening " << args[1] << std::endl;
}

int	main(int argc, char **args)
{
	if (argc == 4)
		replace(args);
	else
		std::cout << "Error, use like this: " << "./Sedesparapringaos file \"string to replace\" \"replacement string\"" << std::endl;
	return 0;
}
