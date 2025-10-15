#include "Array.hpp"
#include <iostream>
#include <string>
#include <stdexcept>


int main()
{
	try{
		Array<int> intArray(5);
		for (size_t i = 0; i < intArray.size(); ++i) 
		{
			intArray[i] = i *10;
		}
		std::cout << "Integer Array:" << std::endl;
		for (size_t i = 0; i < intArray.size(); ++i) 
		{
			std::cout << intArray[i] << std::endl;
		}

		Array<std::string> strArray(3);
		strArray[0] =  "Hello";
		strArray[1] = "World";
		strArray[2] =  "C++";
		std::cout << "\nString Array:" << std::endl;
		for (size_t i = 0; i < strArray.size(); ++i) 
		{
			std::cout << strArray[i] << std::endl;
		}

		std::cout << "\nAccessing out of bounds index:" << std::endl;
		std::cout << intArray[10] << std::endl; // This should throw an exception
	}
	catch (const std::out_of_range& e) 
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}