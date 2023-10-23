/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:20:55 by phijano-          #+#    #+#             */
/*   Updated: 2023/08/02 11:54:16 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

typedef struct s_Data
{
	std::string name; 
	std::string nature;
}	Data;

uintptr_t serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}


int main(void)
{
	Data myData;
	myData.name = "pikachu";
	myData.nature = "lazy";

	uintptr_t ptr;

	std::cout << &myData << std::endl;

	ptr = serialize(&myData);
	std::cout << ptr << std::endl;
	
	std::cout << deserialize(ptr)->name << std::endl;
	std::cout<< deserialize(ptr)->nature << std::endl;

	return 0;
}
