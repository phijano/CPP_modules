#include <iostream>
#include "Array.hpp"

void leaks(void)
{
	system("leaks Array");
}

int main(int, char**)
{

	::Array<int> emptyArray;
	::Array<std::string> (34);
	::Array<float> (6);
	::Array<char> chArray(3);

	try
	{
		for (unsigned int i = 0 ; i < chArray.size() ;i++)
			chArray[i] = 'a' + i;
	}
	catch (std::exception &except)
	{
		std::cout << except.what() << std::endl;
	}

	::Array<char> charCopy(chArray);
	::Array<char> another(20);
	another = charCopy;

	std::cout << "array char" << std::endl;

	try
	{
		for (unsigned int i = 0 ; i < chArray.size() ;i++)
			std::cout << chArray[i] << std::endl;

		std::cout << "Copy array char" << std::endl;

		for (unsigned int i = 0 ; i < charCopy.size() ;i++)
			std::cout << charCopy[i] << std::endl;

		std::cout << "Asigned overload array char" << std::endl;

		for (unsigned int i = 0 ; i < another.size() ;i++)
			std::cout << another[i] << std::endl;

		for (unsigned int i = 0 ; i < chArray.size() ;i++)
			chArray[i] = 'z';

		std::cout << "array char modified" << std::endl;

		for (unsigned int i = 0 ; i < chArray.size() ;i++)
			std::cout << chArray[i] << std::endl;

		std::cout << "Copy array char" << std::endl;

		for (unsigned int i = 0 ; i < charCopy.size() ;i++)
			std::cout << charCopy[i] << std::endl;

		std::cout << "Asigned overload array char" << std::endl;

		for (unsigned int i = 0 ; i < another.size() ;i++)
			std::cout << another[i] << std::endl;
	}
	catch (std::exception &except)
	{
		std::cout << except.what() << std::endl;
	}

	try
	{
		std::cout << "trying to access to element index 100 ..." << std::endl;
		charCopy[100];
	}
	catch (std::exception &except)
	{
		std::cout << except.what() << std::endl;
	}

	atexit(leaks);
    return 0;
}
